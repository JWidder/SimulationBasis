#pragma once

#include "Bestellung.hpp"

namespace simulation
{
	class Development
	{
	private:
		Bestellung _inBestellung;

	public:
		Development();
		~Development();

		void bearbeiteTag();

		void holeBestellung(Bestellung& inBestellung);
		/**
		Arbeiten an der Bestellung für die angegebene Dauer.

		@return Information, ob die Bestellung fertig bearbeitet ist. 
		*/
		bool bearbeiteBestellung(double inDauer);
	};
}
