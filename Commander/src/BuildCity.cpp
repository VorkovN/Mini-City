#include "BuildCity.h"

bool BuildCity::execute(std::vector<std::string> args_vector) const
{
	if (args_vector.size() != 2)
	{
		std::cerr << "wrong count of arguments, required: (name, factory type)" << std::endl;
		return false;
	}

	if(!_world->buildCity(args_vector[0], CarsTypes::getResurcesTypes(args_vector[1])))
		return false;
	return true;
}