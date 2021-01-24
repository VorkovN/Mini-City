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
	explicit City(std::string name, CarsTypes::Types resources_factory_type);

	std::map<CarsTypes::Types, std::list<Train*>>& getRailwayStation();
	std::map<CarsTypes::Types, size_t>& getResources();
	size_t& getPopulation();
	const std::string* getName();
	const ResourceFactory* getResourcefactory();

	~City();
 private:
	const std::string* const _name;
	const ResourceFactory* _resourcefactory{};
	std::map<CarsTypes::Types, size_t> _resources{};
	std::map<CarsTypes::Types, std::list<Train*>> _railway_station;
	size_t _population = 10;
	const size_t _budget = 10;
};
