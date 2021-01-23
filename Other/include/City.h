#pragma once
#include <map>
#include <list>
#include <iostream>
#include <thread>
#include "Resources.h"
#include "ResourceFactory.h"
#include "Train.h"

class ResourceFactory;

class City
{
 public:
	friend class ResourceFactory;

 public:
	explicit City(std::string name, const std::string& resources_factory_type);

	std::list<Train*>& getRailwayStation();

	~City();
	std::list<size_t> test;
 private:
	const std::string* const _name;
	const ResourceFactory* _resourcefactory{};
	std::map<Resources::ResourcesTypes, size_t> _resources{};
	std::list<Train*> _railway_station;
	const size_t _budget = 0;
};
