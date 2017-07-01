#pragma once

#include <vector>
#include <list>
#include "Bestellung.hpp"

namespace simulation
{
	class CustomerErgebnis
	{

	public:
		CustomerErgebnis()
		{
			listeBestellungen = std::list<std::unique_ptr<Bestellung>>();
		}

		~CustomerErgebnis()
		{
			return;
		}

		std::list<std::unique_ptr<Bestellung>> listeBestellungen;
	};
}