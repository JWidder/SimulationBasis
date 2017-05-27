#include "state.hpp"

namespace simulation {


	stateAbort::stateAbort(SimulationDaten& inSimulationDaten) : state(inSimulationDaten)
	{
		return;
	}

	stateType stateAbort::operate()
	{
		return END;
	}
}