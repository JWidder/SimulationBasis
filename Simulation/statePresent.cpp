#include "state.hpp"

namespace simulation
{
	statePresent::statePresent(SimulationDaten& inSimulationDaten) : state(inSimulationDaten)
	{
		return;
	}

	stateType statePresent::operate()
	{
		return END;
	}
}