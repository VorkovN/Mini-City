#pragma once
#include <map>
#include <iostream>
#include "Resources.h"
#include "ResourceCreator.h"

class City
{
public:
	explicit City(std::string name, std::string resources_factory_type);
	~City();
private:
	const std::string *const _name;
	const ResourceFactory *_resourceCreater{};
	const std::map<Resources, size_t> _resources{};
	const size_t _budget = 0;
};
