#include <iostream>

#include "EingabeAusgabe.hpp"
/**

*/

namespace simulation
{
	int main(int argc, char* argv[])
	{
		EingabeAusgabe eingabeAusgabe;
		eingabeAusgabe.starteAusgabe();

		int wert;
		std::cin >> wert;
		return wert;
	}
}