#include "World.h"
#include <iostream>
#include <utility>

World *World::_world = nullptr;

World::World()
{
	std::cout << "World created" << std::endl;
}

void World::buildCity(const std::string &city_name)
{
	_cities.insert({city_name, new City(city_name)});
	std::cout << "build_city " << city_name << std::endl;
}

World *World::GetWorld()
{
	if (_world == nullptr)
		_world = new World();
	return _world;
}
