#pragma once
#include <iostream>
#include <unordered_map>
#include "City.h"

class World
{
private:
	std::unordered_map<std::string, City*> _cities;

public:
	static World *GetWorld();
	World(World &other) = delete;//запрещает клониррование
	void operator=(const World &) = delete;//удаляет присваивание

	bool buildCity(const std::string & city_name, const std::string & resources_factory_type);
	bool buyTrain(const std::string & city_name, const std::string & resources_factory_type, size_t cars_count);

protected:
	static World* _world;

protected:
	World();

};
