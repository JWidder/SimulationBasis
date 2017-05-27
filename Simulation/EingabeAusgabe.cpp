#include "EingabeAusgabe.hpp"

namespace simulation
{
	EingabeAusgabe::EingabeAusgabe(SimulationDaten *inSimulationDaten)
	{
		_simulationDaten = inSimulationDaten;
	}

	void EingabeAusgabe::starteAusgabe()
	{
		std::cout << "**********************************************************" << std::endl;
		std::cout << "*           Simulation der Softwareentwicklung           *" << std::endl;
		std::cout << "**********************************************************" << std::endl;
	}

	bool EingabeAusgabe::selectSimulationstyp()
	{
			std::cout << "==================================================================" << std::endl;
			std::cout << "= Wähle den Simulationsmodus                                     =" << std::endl;
			std::cout << "= 1 Standardmodus                                                =" << std::endl;
			std::cout << "= 2 Oneshotdmodus                                                =" << std::endl;
			std::cout << "= o aktiviere Ausgabe                                            =" << std::endl;
			std::cout << "= x Exit                                                         =" << std::endl;
			do {
				std::cout << "==================================================================" << std::endl;
				std::cout << "= Eingabe (1/2/x) : >> ";
				char s;
				std::cin >> s;
				switch (s) {
				case '1':
					std::cout << "= Standardmodus gewählt                                          =" << std::endl;
					_simulationDaten->setDauerEinschwingen(200);
					_simulationDaten->setAnzahlDurchgang(5);
					_simulationDaten->setDauerDurchgang(60);
					return true;
				case '2':
					std::cout << "= Oneshot Modus gewählt                                          =" << std::endl;
					_simulationDaten->setDauerEinschwingen(200);
					_simulationDaten->setAnzahlDurchgang(1);
					_simulationDaten->setDauerDurchgang(300);
					return true;
				case 'o':
				case 'O':
					_simulationDaten->setPrintOutput(true);
					break;
				case 'x':
					std::cout << "= Programm abgebrochen                                           =" << std::endl;
					return false;
				}
			} while (true);
	}

	/**
	* For each simulation call the progress bar advances by one star.
	*/
	void EingabeAusgabe::ausgabeFortschritt() {
		std::cout << "*";
	}

	/**
	*
	* @param inSimulationDaten
	*/
	void EingabeAusgabe::ausgabeSimulationDaten() {
		std::cout << "==================================================================" << std::endl;
		std::cout << "= Überprüfen der Simulationsparameter                            =" << std::endl;
		std::cout << "==================================================================" << std::endl;
		std::cout << "= Einschwingdauer       = " << _simulationDaten->getDauerEinschwingen() << "                                  =" << std::endl;
		std::cout << "= Dauer des Durchgangs  = " << _simulationDaten->getDauerDurchgang()    << "                                  =" << std::endl;
		std::cout << "= Anzahl der Durchgänge = " << _simulationDaten->getAnzahlDurchgang()   << "                                  =" << std::endl;
	}

	/**
	*
	*/
	void EingabeAusgabe::ausgabeDurchgang() {
		std::cout << "\n";
		std::cout << "==================================================================" << std::endl;
		std::cout << "= Nächster Durchgang                                             =" << std::endl;
		std::cout << "==================================================================" << std::endl;
		std::cout << "= Wähle den nächsten Schritt                                     =" << std::endl;
		std::cout << "= w Weiter                                                       =" << std::endl;
		std::cout << "= a Abbrechen                                                    =" << std::endl;
		std::cout << "= ---> : ";
	}

	/**
	*
	* @return
	*/
	std::string EingabeAusgabe::eingabeDaten()
	{
		std::string eingabeWert;
		std::cin >> eingabeWert;
		return eingabeWert;
	}

	/**
	*
	*/
	void EingabeAusgabe::beendeAusgabe() {
		std::cout << std::endl;
		std::cout << "==================================================================" << std::endl;
		std::cout << "= Simulation beendet                                             =" << std::endl;
		std::cout << "==================================================================" << std::endl;
	}

	/**
	*
	*/
	void EingabeAusgabe::ausgabeAbbrechen() {
		std::cout << "\n" << std::endl;
		std::cout << "==================================================================" << std::endl;
		std::cout << "= Simulation abgebrochen                                         =" << std::endl;
		std::cout << "==================================================================" << std::endl;
	}
}