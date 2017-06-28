#include "Customer.hpp"

namespace simulation
{
	Customer::Customer(SimulationDaten inSimulationDaten) : _simulationDaten(inSimulationDaten)
	{
		return;
	}

	Customer::~Customer()
	{
	}

	// Rückgabe über RVO
	CustomerErgebnis Customer::bearbeiteTag(int nummer)
	{
		CustomerErgebnis tempErgebnis = CustomerErgebnis();

		// Notwendigkeit einer Bestellung ermitteln
		if ((nummer % _simulationDaten.getAbstand()) == 0)
		{
			;
			// std::unique_ptr<Bestellung> _bestellung = std::unique_ptr<Bestellung>(new Bestellung);
			// tempErgebnis.listeBestellungen.push_back(std::move(_bestellung));
		}

		return tempErgebnis;
	}
}