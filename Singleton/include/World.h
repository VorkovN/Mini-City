#pragma once
#include <iostream>
#include <unordered_map>
#include "City.h"

class World
{
private:
	std::unordered_map<std::string, City*> _cities;
	std::unordered_map<std::string, std::string> _c;

public:
	static World *GetWorld();
	World(World &other) = delete;//запрещает клониррование
	void operator=(const World &) = delete;//удаляет присваивание

	void buildCity(const std::string & name, const std::string & factory_type);

protected:
	static World* _world;

protected:
	World();

};
