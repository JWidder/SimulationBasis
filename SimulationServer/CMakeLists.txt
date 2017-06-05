set(SOURCES 	dataframe.cpp 
		dataframe_parser.cpp
			reply.cpp
			request_handler.cpp
			request_parser.cpp
			room.cpp
			server.cpp
			session.cpp)
set(HEADER 	dataframe.hpp 
			dataframe_parser.hpp
			header.hpp
			participant.hpp
			reply.hpp
			request.hpp
			request_handler.hpp
			request_parser.hpp
			room.hpp
			server.hpp
			session.hpp)

include_directories(${Boost_INCLUDE_DIR})
add_library(websocket STATIC ${SOURCES} ${HEADER})
target_include_directories(websocket PUBLIC .)

