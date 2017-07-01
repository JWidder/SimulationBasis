#pragma once

#include <memory>

#include "CustomerErgebnis.hpp"
#include "SimulationDaten.hpp"

namespace simulation
{
	/**
	Kunden erstellen in regelm�ssigen Abst�nden eine oder mehrere Bestellungen,
	die die dann an die Entwicklung �bergeben, die diese dann bearbeitet und als
	Lieferung zurr�ckliefert. 
	*/
	class Customer
	{
	private:
		SimulationDaten _simulationDaten;

	public:
		// TODO Warum wird dieser Konstruktor ben�tigt. 
		Customer() 
		{ 
			return;
		}
		Customer(SimulationDaten inSimulationDaten);
		~Customer();

		std::unique_ptr<CustomerErgebnis> bearbeiteTag(int Tag);
	};
}
