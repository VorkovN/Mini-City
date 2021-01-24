#pragma once
#include <map>
#include <list>
#include <iostream>
#include <thread>
#include "CarsTypes.h"
#include "ResourceFactory.h"
#include "Train.h"

class Train;
class ResourceFactory;

class City
{
 public:

 public:
	explicit City(std::string name, const std::string& resources_factory_type);

	std::list<Train*>& getRailwayStation();
	std::map<CarsTypes::Types, size_t>& getResources();
	size_t& getPopulation();

	~City();
 private:
	const std::string* const _name;
	const ResourceFactory* _resourcefactory{};
	std::map<CarsTypes::Types, size_t> _resources{};
	std::list<Train*> _railway_station;
	size_t _population = 10;
	const size_t _budget = 10;
};
