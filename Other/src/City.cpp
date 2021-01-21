#include "City.h"

#include <utility>


City::City(std::string name):  _name{new std::string(std::move(name))}, _resourceCreater(new ResourceCreater),
								_resources({{Resources::ORE, 0}, {Resources::WOOD, 0},{Resources::LIQUID, 0}})
{

}

City::~City()
{
	delete _resourceCreater;
	delete _name;
}
