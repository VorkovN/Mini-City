#include "City.h"

City::City(std::string name, CarsTypes::Types resources_factory_type): _name{new std::string(std::move(name))},
	_resource_factory(new ResourceFactory(resources_factory_type, this)), _mat_hosp(new MatrinityHospital(this)),
	_resources({{CarsTypes::ORE, 5}, {CarsTypes::WOOD, 5},{CarsTypes::LIQUID, 5}})
{
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
