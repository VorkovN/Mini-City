#include "World.h"
#include <iostream>
#include <utility>

World *World::_world = nullptr;

World::World()
{
	std::cout << "worold created" << std::endl;
}

void World::buildCity(std::string name){
	_c.insert({"name", "c"});

	_cities.insert({"name", new City(std::move(name))});
}

World *World::GetWorld()
{
	if (_world == nullptr)
		_world = new World();
	return _world;
}
