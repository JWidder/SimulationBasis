#pragma once

#include "SimulationDaten.hpp"
#include <iostream>
#include <string>

namespace simulation
{
	/**
	Die Klasse steuert die Kommunikation mit dem Nutzer im Kommandozeilenmodus. 
	*/
	class EingabeAusgabe
	{
	private:
		SimulationDaten *_simulationDaten;
	public:
		EingabeAusgabe(SimulationDaten* inSimulationDaten);
		void starteAusgabe();
		void ausgabeFortschritt();
		void ausgabeSimulationDaten();
		void ausgabeDurchgang();
		std::string eingabeDaten();
		void beendeAusgabe();
		void ausgabeAbbrechen();
		bool selectSimulationstyp();
	};
}