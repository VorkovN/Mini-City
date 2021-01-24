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

	std::cout << "build_city " << *(_cities[city_name]->getName()) << " "
			  << _cities[city_name]->getResourcefactory()->getResource() << std::endl;
	return true;
}

bool World::buyFreightTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count)
{
	if (_cities.find(city_name) == _cities.end())
		return false;

	Train* train = _world->_freighTtrainFactory->createTrain(cars_type, cars_count);
	City* city = _cities.at(city_name);
	city->getRailwayStation()[cars_type].push_back(train);

	std::cout << "buy_freight_train " << city_name << " "
			  << _cities.at(city_name)->getRailwayStation()[cars_type].back()->getCarsType() <<
			  " " << _cities.at(city_name)->getRailwayStation()[cars_type].back()->getCarsCount() << std::endl;
	return true;
}

bool World::buyPassengerTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count)
{
	if (_cities.find(city_name) == _cities.end())
		return false;

	Train* train = _world->_passengerTtrainFactory->createTrain(cars_type, cars_count);
	City* city = _cities.at(city_name);
	city->getRailwayStation()[cars_type].push_back(train);

	std::cout << "buy_freight_train " << city_name << " "
			  << _cities.at(city_name)->getRailwayStation()[cars_type].back()->getCarsType() <<
			  " " << _cities.at(city_name)->getRailwayStation()[cars_type].back()->getCarsCount() << std::endl;
	return true;
}


bool
World::sendTrain(const std::string& name_city_from, const std::string& name_city_to, CarsTypes::Types cars_type, size_t cars_count)
{
	if (_cities.find(name_city_from) == _cities.end() || _cities.find(name_city_to) == _cities.end())
		return false;
	City* city_from = _cities.at(name_city_from);
	City* city_to = _cities.at(name_city_to);

	if(city_from->getRailwayStation()[cars_type].empty())
		return false;

	Train* train = city_from->getRailwayStation()[cars_type].front();

	for (Train* cur_train: city_from->getRailwayStation()[cars_type])
		if (cars_count <= cur_train->getCarsCount() && cur_train->getCarsCount() < train->getCarsCount())
			train = cur_train;

	train->move(city_from, city_to);
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

