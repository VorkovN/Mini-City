#pragma once
#include <map>
#include <iostream>
#include <thread>
#include "ResourcesTypes.h"
#include "ResourceFactory.h"

class ResourceFactory;

class City
{
 public:
	friend class ResourceFactory;

 public:
	explicit City(std::string name, const std::string& resources_factory_type);

	~City();

 private:
	const std::string* const _name;
	const ResourceFactory* _resourceCreater{};
	std::map<Resources::ResourcesTypes, size_t> _resources{};
	const size_t _budget = 0;
};
