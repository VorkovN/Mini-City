#include "City.h"

City::City(std::string name, const std::string& resources_factory_type):
		_name{new std::string(std::move(name))}, _resourcefactory(new ResourceFactory(Resources::getResourcesMap(resources_factory_type), this)),
		_resources({{Resources::ORE, 5}, {Resources::WOOD, 5},{Resources::LIQUID, 5}})
{
	std::cout << "new city" << std::endl;
}

City::~City()
{
	delete _resourcefactory;
	delete _name;
}

std::list<Train*>& City::getRailwayStation()
{
	return _railway_station;
}
