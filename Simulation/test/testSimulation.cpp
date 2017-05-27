#define BOOST_TEST_MODULE "TestSimulation"

#include "boost\test\unit_test.hpp"

#include "..\state.hpp"
#include "..\SimulationDaten.hpp"

namespace simulation
{
	BOOST_AUTO_TEST_SUITE(testState)
		BOOST_AUTO_TEST_CASE(testStateAbort)
	{
		SimulationDaten _simumlationDaten;
		stateAbort *testState = new stateAbort(_simumlationDaten) ;
		state* stateMachine;
		stateMachine = (state *)testState;
		stateMachine->operate();    

		BOOST_CHECK(true);
	}
	BOOST_AUTO_TEST_CASE(test_case3b)
	{
		BOOST_CHECK(false);
	}
	BOOST_AUTO_TEST_CASE(test_case3c)
	{
		BOOST_CHECK(true);
	}
	BOOST_AUTO_TEST_CASE(test_case3d)
	{
		BOOST_CHECK(true);
	}
	BOOST_AUTO_TEST_CASE(test_case3e)
	{
		BOOST_CHECK(true);
	}
	BOOST_AUTO_TEST_CASE(test_case3f)
	{
		BOOST_CHECK(true);
	}
	BOOST_AUTO_TEST_CASE(test_case3g)
	{
		BOOST_CHECK(true);
	}
	BOOST_AUTO_TEST_SUITE_END()
}