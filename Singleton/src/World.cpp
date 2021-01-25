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

	return true;
}

bool World::buyTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count)
{
	if (_cities.find(city_name) == _cities.end())
		return false;

	Train* train;
	if (cars_type < 0)
		train = _world->_passengerTtrainFactory->createTrain(cars_type, cars_count);
	else
		train = _world->_freighTtrainFactory->createTrain(cars_type, cars_count);
	City* city = _cities.at(city_name);
	city->getRailwayStation()[cars_type].push_back(train);

	return true;
}

bool World::sendTrain(const std::string& name_city_from, const std::string& name_city_to, CarsTypes::Types cars_type, size_t cars_count)
{
	if (_cities.find(name_city_from) == _cities.end() || _cities.find(name_city_to) == _cities.end())
		return false;
	City* city_from = _cities.at(name_city_from);
	City* city_to = _cities.at(name_city_to);

	if (city_from->getRailwayStation()[cars_type].empty())
		return false;

	Train* train = city_from->getRailwayStation()[cars_type].front();

	for (Train* cur_train: city_from->getRailwayStation()[cars_type])
		if (cars_count <= cur_train->getCarsCount() && cur_train->getCarsCount() < train->getCarsCount())
			train = cur_train;

	train->move(city_from, city_to, cars_count);
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

bool World::showProducts(const std::string& city_name)
{
	if (_cities.find(city_name) == _cities.end())
		return false;

	City* city = _cities.at(city_name);

	std::cout << std::endl;
	std::cout << "ore: " << city->getResources()[CarsTypes::ORE] << std::endl;
	std::cout << "wood: " << city->getResources()[CarsTypes::WOOD] << std::endl;
	std::cout << "liquid: " << city->getResources()[CarsTypes::LIQUID] << std::endl;
	return true;
}

bool World::showTrains(const std::string& city_name)
{
	if (_cities.find(city_name) == _cities.end())
		return false;

	City* city = _cities.at(city_name);

	std::cout << std::endl;
	std::cout << "bilevel: " << city->getRailwayStation()[CarsTypes::BILEVEL].size() << std::endl;
	std::cout << "simple: " << city->getRailwayStation()[CarsTypes::SIMPLE].size() << std::endl;
	std::cout << "ore: " << city->getRailwayStation()[CarsTypes::ORE].size() << std::endl;
	std::cout << "wood: " << city->getRailwayStation()[CarsTypes::WOOD].size() << std::endl;
	std::cout << "liquid: " << city->getRailwayStation()[CarsTypes::LIQUID].size() << std::endl;
	return true;
}

bool World::showFactories()
{
	std::cout << std::endl;
	for (std::pair<std::string, City*> city: _world->getCities())
		std::cout << *city.second->getName() << ": " << city.second->getResourcefactory()->getResource() << std::endl;
	std::cout << std::endl;
	return true;
}

bool World::showPopulation()
{
	std::cout << std::endl;
	for (std::pair<std::string, City*> city: _world->getCities())
		std::cout << *city.second->getName() << ": " << city.second->getPopulation() << std::endl;
	std::cout << std::endl;
	return true;
}

