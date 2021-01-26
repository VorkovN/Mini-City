#include "City.h"

City::City(std::string name, CarsTypes::Types resources_factory_type)
{
	//_mutex.lock();
	_name = new std::string(std::move(name));
	_resource_factory = new ResourceFactory(resources_factory_type, this);
	_mat_hosp = new MatrinityHospital(this),
			_warehouse = new Warehouse(this),
			_resources = {{ CarsTypes::ORE, 15 }, { CarsTypes::WOOD, 15 }, { CarsTypes::LIQUID, 15 }};
	//_mutex.unlock();
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
		std::_List_iterator<Train*> current = trains.second.begin();
		std::_List_iterator<Train*> next;
		while (*current != NULL)
		{
			next = current++;
			delete *current;
			current = next;
		}
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
