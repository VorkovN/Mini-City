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
	explicit City(std::string name, CarsTypes::Types resources_factory_type);

	///GETTERS///
	std::map<CarsTypes::Types, std::list<Train*>>& getRailwayStation();
	std::map<CarsTypes::Types, size_t>& getResources();
	const size_t getPopulation() const;
	const size_t getBudget() const;
	const std::string* getName() const;
	const ResourceFactory* getResourcefactory() const;
	std::mutex& getMutex();
	///GETTERS///

	///SETTERS///
	void setPopulation(size_t population);
	void setBudget(size_t budget);
	///SETTERS///

	~City();
 private:
	const std::string* const _name;//вернуть конст
	const ResourceFactory* _resource_factory;//создает ресурсы в отдельном потоке
	const MatrinityHospital* _mat_hosp;//создает население в отдельном потоке
	const Warehouse* _warehouse;//скупает ресурсы со склада в 3 отдельных шаблонных потоках
	std::map<CarsTypes::Types, size_t> _resources;//хранилище ресурсов города
	std::map<CarsTypes::Types, std::list<Train*>> _railway_station;//хранилище поездов
	size_t _population = 10;//население города
	size_t _budget = 100;//бюджет города
	std::mutex _mutex;
};
