#pragma once

// #include "state.hpp"
#include <string>

namespace simulation
{
	class SimulationDaten {
	private:
		int _dauerEinschwingen;
		int _dauerDurchgang;
		int _anzahlDurchgang;
		bool _isPrintOutput;

	public:
		int getDauerEinschwingen() { return _dauerEinschwingen; }
		void setDauerEinschwingen(int dauerEinschwingen) { _dauerEinschwingen = dauerEinschwingen; }

		int getDauerDurchgang() { return _dauerDurchgang; }
		void setDauerDurchgang(int dauerDruchgang) { _dauerDurchgang = dauerDruchgang; }

		int getAnzahlDurchgang() { return _anzahlDurchgang; }
		void setAnzahlDurchgang(int anzahlDurchgang) { _anzahlDurchgang = anzahlDurchgang; }

		int getPrintOutput() { return _isPrintOutput; }
		void setPrintOutput(bool isPrintOutput) { _isPrintOutput = isPrintOutput; }
	};
}