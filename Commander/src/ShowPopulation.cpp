#include "ShowPopulation.h"

bool ShowPopulation::execute() const
{
	if(!_world->showPopulation())
		return false;
	return true;
}