#include "server.hpp"

#include "EingabeAusgabe.hpp"

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;

/**
* @brief Main opens starts simulation:
+ 
* Commandline Parameters:
* 
* No parameter: Start Commandline Version
* server -s  0.0.0.0 7777 Opens a web socket.
* 
* Das Hauptprogramm kann entweder als Webserver oder als Kommandozeielnversion aufgerufen werden. 
* 
* 
* @return 0: --> Success 1: something went wrong
*/
int main(int argc, char* argv[])
{
	pt::ptree root;

	root.put("height", 12.0);
	root.put("some.complex.path", "bonjour");

	std::stringstream testJson;

	// pt::write_json("test.json", root);
	pt::write_json(testJson, root);
	// pt::write_json(std::cout, root);


	try
	{
		// Check command line arguments.
		if (argc == 3)
		{
			std::cout << "Server address: " << argv[1] << std::endl;
			std::cout << "Server port: " << argv[2] << std::endl;
			std::cout << "Server is starting..." << std::endl;

			// Initialise the server.
			websocket::applications::chat::server s(argv[1], argv[2]);

			std::cout << "Server has started." << std::endl;
			std::cout << "Press Ctrl+C (Ctrl+Break) to exit." << std::endl << std::endl;
			// Run the server until stopped.
			s.run();
		}
		else if (argc == 1)
		{
			std::cout << "Kommandozeilen Version" << std::endl;

			simulation::SimulationDaten simulationDaten;
			simulation::EingabeAusgabe eingabeAusgabe(&simulationDaten);

			eingabeAusgabe.starteAusgabe();

			simulationDaten.setAnzahlDurchgang(12);
			eingabeAusgabe.selectSimulationstyp();
			eingabeAusgabe.ausgabeSimulationDaten();

			for (int i = 0; i < simulationDaten.getAnzahlDurchgang(); i++)
			{
				eingabeAusgabe.ausgabeDurchgang();
				eingabeAusgabe.eingabeDaten();
			}

			return 0;
		}
		else
		{
			std::cerr << "Usage: server <address> <port>\n";
			std::cerr << "  For IPv4, try:\n";
			std::cerr << "    server -s 0.0.0.0 7777\n";
			std::cerr << "  For IPv6, try:\n";
			std::cerr << "    server 0::0 7777\n";
			return 1;
		}
	}
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return 0;
}