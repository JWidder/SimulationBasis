#pragma once

#include <vector>
#include "Bestellung.hpp"

namespace simulation
{
	class CustomerErgebnis
	{
	public:
		CustomerErgebnis()
		{
			listeBestellungen = std::vector<Bestellung>();
		}

		~CustomerErgebnis()
		{
			return;
		}
		std::vector<Bestellung> listeBestellungen;
	};
}