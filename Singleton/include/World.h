#pragma once

#include <iostream>
#include <unordered_map>
#include "City.h"
#include "TrainFactory.h"
#include "PassengerTrainFactory.h"
#include "FreightTrainFactory.h"

class World
{
 public:
	TrainFactory* _freighTtrainFactory = new FreightTrainFactory;
	TrainFactory* _passengerTtrainFactory = new PassengerTrainFactory;

 private:
	std::unordered_map<std::string, City*> _cities;

 public:
	static World* GetWorld();

	World(World& other) = delete;
	void operator=(const World&) = delete;
	std::unordered_map<std::string, City*>& getCities();

	bool buildCity(const std::string& city_name, CarsTypes::Types resources_factory_type);
	bool buyFreightTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count);
	bool buyPassengerTrain(const std::string& city_name, CarsTypes::Types cars_type, size_t cars_count);
	bool sendTrain(const std::string& city_from, const std::string& city_to, CarsTypes::Types cars_type, size_t cars_count);
	bool showProducts(const std::string& city);
	bool showTrains(const std::string& city);
	bool showFactories();
	bool showPopulation();

 protected:
	static World* _world;

 protected:
	World();

};
