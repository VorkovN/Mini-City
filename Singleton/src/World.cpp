#include "World.h"
#include <iostream>
#include <utility>

World* World::_world = nullptr;

World::World()
{
	std::cout << "World created" << std::endl;
}

bool World::buildCity(const std::string& city_name, CarsTypes::Types resources_factory_type)
{
	if (!_cities.contains(city_name))
		_cities.insert({ city_name, new City(city_name, resources_factory_type) });
	else
		return false;

	std::cout << "build_city " << *(_cities[city_name]->getName()) << " " << _cities[city_name]->getResourcefactory()->getResource() << std::endl;
	return true;
}

bool World::buyFreightTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count)
{
	if (_cities.find(city_name) == _cities.end())
		return false;

	Train* train = _world->_freighTtrainFactory->createTrain(cars_type, cars_count);
	City* city = _cities.at(city_name);
	city->getRailwayStation().push_back(train);

	std::cout << "buy_freight_train " << city_name << " " << _cities.at(city_name)->getRailwayStation().back()->getCarsType() <<
			  " " << _cities.at(city_name)->getRailwayStation().back()->getCarsCount() << std::endl;
	return true;
}

bool World::buyPassengerTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count)
{
	if (_cities.find(city_name) == _cities.end())
		return false;

	Train* train = _world->_passengerTtrainFactory->createTrain(cars_type, cars_count);
	City* city = _cities.at(city_name);
	city->getRailwayStation().push_back(train);

	std::cout << "buy_freight_train " << city_name << " " << _cities.at(city_name)->getRailwayStation().back()->getCarsType() <<
			  " " << _cities.at(city_name)->getRailwayStation().back()->getCarsCount() << std::endl;
	return true;
}

World* World::GetWorld()
{
	if (_world == nullptr)
		_world = new World();
	return _world;
}

std::unordered_map<std::string, City*>& World::getCities()
{
	return _cities;
}

