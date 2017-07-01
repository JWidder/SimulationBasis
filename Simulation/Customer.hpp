#pragma once

#include <memory>

#include "CustomerErgebnis.hpp"
#include "SimulationDaten.hpp"

namespace simulation
{
	/**
	Kunden erstellen in regelmässigen Abständen eine oder mehrere Bestellungen,
	die die dann an die Entwicklung übergeben, die diese dann bearbeitet und als
	Lieferung zurrückliefert. 
	*/
	class Customer
	{
	private:
		SimulationDaten _simulationDaten;

	public:
		// TODO Warum wird dieser Konstruktor benötigt. 
		Customer() 
		{ 
			return;
		}
		Customer(SimulationDaten inSimulationDaten);
		~Customer();

		std::unique_ptr<CustomerErgebnis> bearbeiteTag(int Tag);
	};
}
