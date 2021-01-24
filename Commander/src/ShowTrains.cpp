#include "ShowTrains.h"

bool ShowTrains::execute(std::vector<std::string> args_vector)  const
{
	if(!_world->showTrains(args_vector[0]))
		return false;
	return true;

}