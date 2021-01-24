#include "BuildCity.h"

bool BuildCity::execute(std::vector<std::string> args_vector) const
{
	if (args_vector.size() != 2)
		return false;
	if(!_world->buildCity(args_vector[0], CarsTypes::getFrCarTypes(args_vector[1])))
		return false;
	return true;
}