#include "City.h"

City::City(std::string name, CarsTypes::Types resources_factory_type) : _name(new std::string(std::move(name))),
	_resources({{ CarsTypes::ORE, 5 }, { CarsTypes::WOOD, 5 }, { CarsTypes::LIQUID, 5 }})
{
	_resource_factory = new ResourceFactory(resources_factory_type, *this);
	_mat_hosp = new MatrinityHospital(*this);
	_warehouse = new Warehouse(*this);
	std::cout << "new city" << std::endl;
}

City::~City()
{

	delete _resource_factory;
	delete _name;
	delete _mat_hosp;
	delete _warehouse;

	for (std::pair<CarsTypes::Types, std::list<Train*>> trains : _railway_station)
	{
		for(Train* train : trains.second)
			delete train;
	}

}

///GETTERS///
std::map<CarsTypes::Types, std::list<Train*>>& City::getRailwayStation()
{
	return _railway_station;
}

std::map<CarsTypes::Types, size_t>& City::getResources()
{
	return _resources;
}

const std::string* City::getName() const
{
	return _name;
}

const ResourceFactory* City::getResourcefactory() const
{
	return _resource_factory;
}

const size_t City::getPopulation() const
{
	return _population;
}

const size_t City::getBudget() const
{
	return _budget;
}

std::mutex& City::getMutex()
{
	return _mutex;
}
///GETTERS///

///SETTERS///
void City::setPopulation(size_t population)
{
	_population = population;
}

void City::setBudget(size_t budget)
{
	_budget = budget;
}
///SETTERS///
