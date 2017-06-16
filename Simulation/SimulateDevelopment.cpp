#include "SimulateDevelopment.hpp"
#include <iostream>

namespace simulation
{
	SimulateDevelopment::SimulateDevelopment()
	{
		SimulationDaten tempSimulationDaten = SimulationDaten();
		tempSimulationDaten.setAbstand(20);


		_customer = Customer(tempSimulationDaten);
		_development = Development();
	}

	SimulateDevelopment::~SimulateDevelopment()
	{
	}

	SimulationErgebnis SimulateDevelopment::bearbeiteTag()
	{
		SimulationErgebnis tempSimulationErgebnis = SimulationErgebnis();
		_customer.bearbeiteTag(1);
		_development.bearbeiteTag();
		return tempSimulationErgebnis;
	}
}