#pragma once

#include "Customer.hpp"
#include "Development.hpp"
#include "SimulationErgebnis.hpp"

namespace simulation
{
	/**
	Diese Klasse kapselt den Ablauf der Simulation. Dazu wird die Methode 
	bearbeiteTag f�r jeden simulierten Tag aufgerufen. Diese Methode liefert 
	f�r jeden Tag dei Ergebnisse in dem Objekt resultDevelopment.
	*/
	class SimulateDevelopment
	{
	private:
		Customer _customer;
		Development _development;

	public:
		SimulateDevelopment();
		~SimulateDevelopment();

		SimulationErgebnis bearbeiteTag();
	};
}