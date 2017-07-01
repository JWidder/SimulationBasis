#include "boost\test\unit_test.hpp"

#include "Customer.hpp"

namespace simulation
{
	BOOST_AUTO_TEST_SUITE(test_Customer)
		BOOST_AUTO_TEST_CASE(test_bearbeiteTag)
		{
			SimulationDaten tempSimulationDaten = SimulationDaten();
			tempSimulationDaten.setAbstand(20);

			Customer tempCustomer = Customer(tempSimulationDaten);

			auto result = tempCustomer.bearbeiteTag(1);
			BOOST_CHECK(result->listeBestellungen.size()==0);
			result = tempCustomer.bearbeiteTag(20);
			BOOST_CHECK(result->listeBestellungen.size() == 1);
			result = tempCustomer.bearbeiteTag(39);
			BOOST_CHECK(result->listeBestellungen.size() == 0);
			result = tempCustomer.bearbeiteTag(40);
			BOOST_CHECK(result->listeBestellungen.size() == 1);
			result->~CustomerErgebnis();
			result->~CustomerErgebnis();
	}
	BOOST_AUTO_TEST_SUITE_END()
}