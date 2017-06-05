#include "session.hpp"
#include "reply.hpp"
#include "request.hpp"
#include "request_handler.hpp"
#include "header.hpp"
#include <iostream>
#include <vector>
#include <string>

#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>
#include <boost/uuid/sha1.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/insert_linebreaks.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/ostream_iterator.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;

namespace websocket {
    namespace applications {
        namespace chat {

            session::session(boost::asio::io_service& io_service, room& room)
                : state_(undefined_state), strand_(io_service),
                socket_(io_service), room_(room)
            {
            }

            boost::asio::ip::tcp::socket& session::socket()
            {
                return socket_;
            }

            void session::start()
            {
                state_ = reading_handshake;          
                socket_.async_read_some(boost::asio::buffer(buff_),
                    strand_.wrap(
                    boost::bind(&session::handle_read, shared_from_this(),
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred)));

				std::cout << "Initiale Daten: " << buff_.elems << std::endl;
            }

            void session::handle_read(const boost::system::error_code& error,
                std::size_t bytes_transferred)
            {
                if (!error)
                {
					std::cout << ">>> Nachricht empfangen" << std::endl;
					if (state_ == reading_handshake)
                    {
						std::cout << ">>> >>> Initialisierung" << std::endl;
						boost::tribool result;
                        boost::tie(result, boost::tuples::ignore) = req_parser_.parse(
                            req_, buff_.data(), buff_.data() + bytes_transferred);

						// Ausgabe der Daten
						for (std::vector<http::header>::const_iterator i = req_.headers.cbegin();
							i != req_.headers.cend(); ++i)
						{
							std::cout << "Wert " << i->name << " Value: " << i->value << std::endl;
						}

                        if (result)
                        {
                            http::request_handler::handle_request(req_, reply_);

                            state_ = writing_handshake;
                            boost::asio::async_write(socket_, reply_.to_buffers(),
                                strand_.wrap(
                                boost::bind(&session::handle_write, shared_from_this(),
                                boost::asio::placeholders::error)));
                        }
                        else if (!result)
                        {
                            state_ = bad_request;                        
                            reply_ = http::reply::stock_reply(http::reply::bad_request);
                            boost::asio::async_write(socket_, reply_.to_buffers(),
                                strand_.wrap(
                                boost::bind(&session::handle_write, shared_from_this(),
                                boost::asio::placeholders::error)));
                        }
                        else
                        {
                            socket_.async_read_some(boost::asio::buffer(buff_),
                                strand_.wrap(
                                boost::bind(&session::handle_read, shared_from_this(),
                                boost::asio::placeholders::error,
                                boost::asio::placeholders::bytes_transferred)));
                        }
                    }
                    else if (state_ == pumping_messages)
                    {
						std::cout << ">>> >>> Standardnachricht" << std::endl;

                        boost::tribool result;
                        boost::tie(result, boost::tuples::ignore) = frame_parser_.parse(
                            read_frame_, buff_.data(), buff_.data() + bytes_transferred);

						std::string ausgabe(read_frame_.payload.begin(), read_frame_.payload.end());

						// Nachricht wurde im JSON-Format entgegen genommen.
						pt::ptree pt2;
						std::istringstream is(ausgabe);
						read_json(is, pt2);
						std::cout << "quality: " << pt2.get<std::string>("quality","test") << std::endl;
						std::cout << "function: " << pt2.get<std::string>("function", "test") << std::endl;
						std::cout << "kosten: " << pt2.get<std::string>("kosten", "test") << std::endl;

						std::cout << "Wert: " << ausgabe << " <<" << std::endl;

						std::string wert = "test an Web";
						std::vector<unsigned char> v(wert.begin(), wert.end());
						read_frame_.payload = v;

                        if (result)
                        {
                            if (read_frame_.opcode == dataframe::text_frame)
                            {
								std::cout << "--> Jetzt werden die Werte ausgegeben: " << std::endl;
								// Ausgabe der Antwort
                                room_.deliver(read_frame_, shared_from_this());

                                read_frame_.payload.clear();
                                frame_parser_.reset();

                                socket_.async_read_some(boost::asio::buffer(buff_),
                                    strand_.wrap(
                                    boost::bind(&session::handle_read, shared_from_this(),
                                    boost::asio::placeholders::error,
                                    boost::asio::placeholders::bytes_transferred)));
                            }
                            else if (read_frame_.opcode == dataframe::pong ||
                                read_frame_.opcode == dataframe::ping)
                            {
                                read_frame_.payload.clear();
                                frame_parser_.reset();

                                socket_.async_read_some(boost::asio::buffer(buff_),
                                    strand_.wrap(
                                    boost::bind(&session::handle_read, shared_from_this(),
                                    boost::asio::placeholders::error,
                                    boost::asio::placeholders::bytes_transferred)));
                            }
                            else
                            {
                                room_.leave(shared_from_this());
                            }
                        }
                        else if (!result)
                        {
							std::cout << ">>> >>> Leave Nachricht" << std::endl;
							room_.leave(shared_from_this());
                        }
                        else
                        {
                            socket_.async_read_some(boost::asio::buffer(buff_),
                                strand_.wrap(
                                boost::bind(&session::handle_read, shared_from_this(),
                                boost::asio::placeholders::error,
                                boost::asio::placeholders::bytes_transferred)));
                        }
                    }
                }
                else
                {
                    if (error != boost::asio::error::eof)
                        std::cerr << error.message() << std::endl;

                    room_.leave(shared_from_this());
                }

                // If an error occurs then no new asynchronous operations are started. This
                // means that all shared_ptr references to the connection object will
                // disappear and the object will be destroyed automatically after this
                // handler returns. The connection class's destructor closes the socket.
            }

            void session::handle_write(const boost::system::error_code& error)
            {
                if (!error)
                {
					std::cout << ">>> Schreiben der Werte" << std::endl;
                    if (state_ == writing_handshake)
                    {
						std::cout << ">>> >>> Antwort auf Initialisierung" << std::endl;
						state_ = pumping_messages;

                        room_.join(shared_from_this());

                        socket_.async_read_some(boost::asio::buffer(buff_),
                                    strand_.wrap(
                                    boost::bind(&session::handle_read, shared_from_this(),
                                    boost::asio::placeholders::error,
                                    boost::asio::placeholders::bytes_transferred)));
                    }
                    else if (state_ == pumping_messages)
                    {
						std::cout << ">>> >>> Antwort auf Standardnachricht" << std::endl;
						if (!write_msgs_.empty())
                        {
                            write_msgs_.pop_front();
                            if (!write_msgs_.empty())
                            {
                                boost::asio::async_write(socket_,
                                    write_msgs_.front().to_buffers(),
                                    strand_.wrap(boost::bind(&session::handle_write, shared_from_this(),
                                    boost::asio::placeholders::error)));
                            }
                        }
                    }
                }
                else
                {
                    if (error != boost::asio::error::eof)
                        std::cerr << error.message() << std::endl;

                    room_.leave(shared_from_this());
                }
            }

            void session::deliver(dataframe msg)
            {
                bool write_in_progress = !write_msgs_.empty();
                write_msgs_.push_back(msg);
                if (!write_in_progress)
                {
                    boost::asio::async_write(socket_,
                        write_msgs_.front().to_buffers(),
                        strand_.wrap(boost::bind(&session::handle_write, shared_from_this(),
                        boost::asio::placeholders::error)));
                }
            }

            std::string session::get_id()
            {
                return socket_.is_open() ? "user" + boost::lexical_cast<std::string>(socket_.remote_endpoint().port()) : "user0";
            }

        } // namespace chat
    } // namespace applications
} // namespace websocket