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

	CustomerErgebnis Customer::bearbeiteTag(int nummer)
	{
		CustomerErgebnis tempErgebnis = CustomerErgebnis();

		// Notwendikeit einer Bestellung ermitteln
		if ((nummer % _simulationDaten.getAbstand()) == 0)
		{
			Bestellung tempBestellung = Bestellung(10);
			tempErgebnis.listeBestellungen.push_back(tempBestellung);
		}

		return tempErgebnis;
	}
}