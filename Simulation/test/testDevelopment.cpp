// #define BOOST_TEST_MODULE "SimulationBasisTests"
#include "boost\test\unit_test.hpp"

#include "Development.hpp"
#include "Bestellung.hpp"

namespace simulation 
{
	BOOST_AUTO_TEST_SUITE(test_Development)
	/*
	Bestellung bearbeiten
	Project  Manager orders the the development organization to implement an order.


	*/
	BOOST_AUTO_TEST_CASE(test_BearbeiteGrosseBestellung)
	{
		Development _development = Development();
		Bestellung _bestellung = Bestellung(10);

		_development.holeBestellung(_bestellung);
		bool result = _development.bearbeiteBestellung(8.0);
		BOOST_CHECK(!result);

		result = _development.bearbeiteBestellung(8.0);
		BOOST_CHECK(result);
	}

	BOOST_AUTO_TEST_CASE(test_BearbeiteKleineBestellung)
	{
		Development _development = Development();
		Bestellung _bestellung = Bestellung(6.0);

		_development.holeBestellung(_bestellung);
		bool result = _development.bearbeiteBestellung(8.0);
		BOOST_CHECK(result);
	}
	BOOST_AUTO_TEST_SUITE_END()
}