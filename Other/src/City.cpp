#include "City.h"

City::City(std::string name, CarsTypes::Types resources_factory_type)
{
	//_mu.lock();
	_name = new std::string(std::move(name));
	_resource_factory = new ResourceFactory(resources_factory_type, this);
	_mat_hosp = new MatrinityHospital(this),
	_warehouse = new Warehouse(this),
	_resources = {{CarsTypes::ORE, 15}, {CarsTypes::WOOD, 15},{CarsTypes::LIQUID, 15}};
	//_mu.unlock();
	std::cout << "new city" << std::endl;
}

City::~City()
{
	delete _resource_factory;
	delete _name;
}

std::map<CarsTypes::Types, std::list<Train*>>& City::getRailwayStation()
{
	return _railway_station;
}

std::map<CarsTypes::Types, size_t>& City::getResources()
{
	return _resources;
}

size_t& City::getPopulation()
{
	return _population;
}

const std::string* City::getName()
{
	return _name;
}

const ResourceFactory* City::getResourcefactory()
{
	return _resource_factory;
}
