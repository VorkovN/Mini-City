#include "BuildCity.h"

bool BuildCity::execute() const
{
	_world->buildCity("city");
	std::cout << "build_city" << std::endl;
	return true;
}