#include "Bestellung.hpp"

namespace simulation
{
	Bestellung::Bestellung() : size(10), restDauer(10)
	{
	}

	Bestellung::Bestellung(double inSize)
	{
		size = inSize;
		restDauer = inSize;
	}

	Bestellung::~Bestellung()
	{
	}

	double Bestellung::getSize()
	{
		return size;
	}

	BestellungErgebnis Bestellung::bearbeiteBestellung(double dauer)
	{
		BestellungErgebnis _bestellungErgebnis;
		if (restDauer > dauer)
		{
			restDauer -= dauer;
			_bestellungErgebnis.restDauer = 0;
			_bestellungErgebnis.status = false;
		}
		else
		{
			_bestellungErgebnis.restDauer = dauer - restDauer;
			restDauer = 0;
			_bestellungErgebnis.status = true;
		}
		return _bestellungErgebnis;
	}
}