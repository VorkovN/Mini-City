#include "ShowFactories.h"

bool ShowFactories::execute()  const
{
	if(!_world->showFactories())
		return false;
	return true;
}