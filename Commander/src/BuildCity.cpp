#include "BuildCity.h"

bool BuildCity::execute(std::string args_string) const
{
	std::istringstream args_stream(args_string);
	std::string city_name;
	args_stream >> city_name;
	_world->buildCity(city_name);
	return true;
}