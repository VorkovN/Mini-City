#pragma once
#include <map>
#include <list>
#include <iostream>
#include <thread>
#include "CarsTypes.h"
#include "ResourceFactory.h"
#include "MaternityHospital.h"
#include "Warehouse.h"
#include "Train.h"

class Train;
class ResourceFactory;
class MatrinityHospital;
class Warehouse;

class City
{
 public:
	friend class ResourceFactory;
	friend class MatrinityHospital;
	friend class Warehouse;

 public:
	explicit City(std::string name, CarsTypes::Types resources_factory_type);

	std::map<CarsTypes::Types, std::list<Train*>>& getRailwayStation();
	std::map<CarsTypes::Types, size_t>& getResources();
	size_t& getPopulation();
	size_t& getBudget();
	const std::string* getName();
	const ResourceFactory* getResourcefactory();

	~City();
 private:
	const std::string* _name;//вернуть конст
	const ResourceFactory* _resource_factory;
	const MatrinityHospital* _mat_hosp;
	const Warehouse* _warehouse;
	std::map<CarsTypes::Types, size_t> _resources;
	std::map<CarsTypes::Types, std::list<Train*>> _railway_station;
	size_t _population = 10;
	size_t _budget = 100;
	std::mutex _mu;
};
