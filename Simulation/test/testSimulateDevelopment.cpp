// #define BOOST_TEST_MODULE "SimulationBasisTests"
#include "boost\test\unit_test.hpp"

#include "SimulateDevelopment.hpp"

namespace simulation
{
	BOOST_AUTO_TEST_SUITE(test_SimulationDevelopment)
		BOOST_AUTO_TEST_CASE(test_TagBearbeiten)
	{
		SimulateDevelopment _simulateDevelopment;

		SimulationErgebnis result = _simulateDevelopment.bearbeiteTag();
		result.status = true;

		BOOST_CHECK(result.status);
	}
	BOOST_AUTO_TEST_SUITE_END()
}