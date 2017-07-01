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
	std::unique_ptr<CustomerErgebnis>  Customer::bearbeiteTag(int nummer)
	{
		std::unique_ptr<CustomerErgebnis> tempErgebnis = std::unique_ptr<CustomerErgebnis> (new CustomerErgebnis());

		// Notwendigkeit einer Bestellung ermitteln
		if ((nummer % _simulationDaten.getAbstand()) == 0)
		{
			std::unique_ptr<Bestellung> _bestellung = std::unique_ptr<Bestellung>(new Bestellung);
			tempErgebnis->listeBestellungen.push_back(std::move(_bestellung));
		}

		return tempErgebnis;
	}
}