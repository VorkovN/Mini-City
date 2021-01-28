#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include "City.h"
#include "TrainFactory.h"
#include "PassengerTrainFactory.h"
#include "FreightTrainFactory.h"



class World
{
 protected:
	World();

 public:
	~World();

	static World* getCreatedWorld();

	World(World& other) = delete;
	void operator=(const World&) = delete;
	std::unordered_map<std::string, City*>& getCities();

	bool buildCity(const std::string& city_name, CarsTypes::Types resources_factory_type);
	bool buyTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count);
	bool sellTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count);
	bool sendTrain(const std::string& city_from, const std::string& city_to, CarsTypes::Types cars_type, size_t cars_count);
	bool showProducts(const std::string& city);
	bool showTrains(const std::string& city);
	bool showFactories();
	bool showPopulation();
	bool showBudget();

 protected:
	static World* _world;

 public:
	static bool ALIVE_WORLD;//чтобы проверять наличие мира из потоков и закрывать их
	TrainFactory* _freighTtrainFactory = new FreightTrainFactory;//фабрика товарных поездов
	TrainFactory* _passengerTtrainFactory = new PassengerTrainFactory;//фабрика пассажирских поездов

 private:
	std::unordered_map<std::string, City*> _cities;//карта городов
};
