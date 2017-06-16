// #define BOOST_TEST_MODULE "SimulationBasisTests"
#include "boost\test\unit_test.hpp"
#include "Bestellung.hpp"

namespace simulation
{
	BOOST_AUTO_TEST_SUITE(test_Bestellung)
		BOOST_AUTO_TEST_CASE(test_GrosseBestellungBearbeiten)
	{
		Bestellung tempBestellung(16);

		BestellungErgebnis result = tempBestellung.bearbeiteBestellung(8);

		BOOST_CHECK(!result.status);
		BOOST_CHECK(result.restDauer == 0);

		result = tempBestellung.bearbeiteBestellung(8);

		BOOST_CHECK(result.status);
		BOOST_CHECK(result.restDauer < 0.0000000001);
	}

	BOOST_AUTO_TEST_CASE(test_GrosseBestellungBearbeitenMitRest)
	{
		Bestellung tempBestellung(15);
		BestellungErgebnis result = tempBestellung.bearbeiteBestellung(8);

		BOOST_CHECK(!result.status);
		BOOST_CHECK(result.restDauer == 0);

		result = tempBestellung.bearbeiteBestellung(8);

		BOOST_CHECK(result.status);
		BOOST_CHECK((result.restDauer - 1.0) < 0.0000000001);
	}

	BOOST_AUTO_TEST_CASE(test_BestellungBearbeiten)
	{
		Bestellung tempBestellung(7);
		BestellungErgebnis result = tempBestellung.bearbeiteBestellung(8);

		BOOST_CHECK(result.status);
		BOOST_CHECK((result.restDauer - 1.0) < 0.0000000001);
	}

	BOOST_AUTO_TEST_SUITE_END()
}