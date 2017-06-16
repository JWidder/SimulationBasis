#include "boost\test\unit_test.hpp"

#include "Lieferung.hpp"

namespace simulation
{
	BOOST_AUTO_TEST_SUITE(testState)
		BOOST_AUTO_TEST_CASE(test_Lieferung)
	{
		simulation::Lieferung tempLieferung=Lieferung();
		BOOST_CHECK(true);
	}
	BOOST_AUTO_TEST_SUITE_END()
}