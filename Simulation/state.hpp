#pragma once

#include "SimulationDaten.hpp"

namespace simulation
{
	enum stateType {
		PREPARE, SIMULATE, PRESENT, FEEDBACK, ABORT, END
	};

	class state {

	public:

		SimulationDaten& simulationDaten;

		state(SimulationDaten& inSimulationDaten);
		virtual stateType operate() = 0;
	};

	class statePresent :public state {
	public:
		statePresent(SimulationDaten& inSimulationDaten);
		virtual stateType operate();
	};

	class stateSimulation {
	public:
		stateSimulation();
		virtual stateType operate();
	};

	class statePrepare {
	public:
		statePrepare();
		virtual stateType operate();
	};

	class stateFeedback {
	public:
		stateFeedback();
		virtual stateType operate();
	};

	class stateAbort : public state {
	public:
		stateAbort(SimulationDaten& inSimulationDaten);
		virtual stateType operate();
	};
}
