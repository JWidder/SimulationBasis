#include "Development.hpp"



simulation::Development::Development() : _inBestellung {Bestellung((double)0.0)}
{
	return;
}


simulation::Development::~Development()
{
}

void simulation::Development::bearbeiteTag()
{
}

void simulation::Development::holeBestellung(Bestellung& inBestellung)
{
	_inBestellung = inBestellung;
}

bool simulation::Development::bearbeiteBestellung(double inDauer)
{
	return (_inBestellung.bearbeiteBestellung(inDauer).status);
}
