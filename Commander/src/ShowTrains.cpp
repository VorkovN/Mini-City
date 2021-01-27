#include "ShowTrains.h"

bool ShowTrains::execute(std::vector<std::string> args_vector)  const
{
	if (args_vector.size() != 1)
	{
		std::cerr << "wrong count of arguments, required: (city name)" << std::endl;
		return false;
	}

	if(!_world->showTrains(args_vector[0]))
		return false;
	return true;

}