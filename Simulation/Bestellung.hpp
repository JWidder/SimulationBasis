#pragma once
#include "BestellungErgebnis.hpp"

namespace simulation
{
	class Bestellung
	{
	private:
		double size;
		double restDauer;

	public:
		Bestellung(double inSize=10.0);
		~Bestellung();

		double getSize();
		BestellungErgebnis bearbeiteBestellung(double dauer);
	};
}
