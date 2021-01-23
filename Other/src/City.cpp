#include "City.h"

City::City(std::string name, const std::string& resources_factory_type):
								_name{new std::string(std::move(name))}, _resourceCreater(new ResourceFactory(Resources::getResourcesMap(resources_factory_type), this)),
								_resources({{Resources::ORE, 0}, {Resources::WOOD, 0},{Resources::LIQUID, 0}})
{
	std::cout << "new city" << std::endl;
}

City::~City()
{
	delete _resourceCreater;
	delete _name;
}
