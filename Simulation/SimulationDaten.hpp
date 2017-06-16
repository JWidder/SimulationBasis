#pragma once

// #include "state.hpp"
#include <string>

namespace simulation
{
	class SimulationDaten {
	private:
		// Eigenschaften der Simulation
		int _dauerEinschwingen;
		int _dauerDurchgang;
		int _anzahlDurchgang;
		bool _isPrintOutput;
		// Podukteigenschaften
		double _basisGr�sse;
		int _abstand;

	public:
		int getDauerEinschwingen() { return _dauerEinschwingen; }
		void setDauerEinschwingen(int dauerEinschwingen) { _dauerEinschwingen = dauerEinschwingen; }

		int getDauerDurchgang() { return _dauerDurchgang; }
		void setDauerDurchgang(int dauerDruchgang) { _dauerDurchgang = dauerDruchgang; }

		int getAnzahlDurchgang() { return _anzahlDurchgang; }
		void setAnzahlDurchgang(int anzahlDurchgang) { _anzahlDurchgang = anzahlDurchgang; }

		int getPrintOutput() { return _isPrintOutput; }
		void setPrintOutput(bool isPrintOutput) { _isPrintOutput = isPrintOutput; }
	
		double getBasisGr�sse() { return _basisGr�sse; }
		void setBasisGroesse(double inBasisGroesse) { _basisGr�sse = inBasisGroesse; }

		int getAbstand() { return _abstand; }
		void setAbstand(int inAbstand) { _abstand = inAbstand; }
	};
}