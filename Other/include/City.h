#pragma once
#include <map>
#include <iostream>
#include "Resources.h"
#include "ResourceCreator.h"

class City
{
public:
	explicit City(std::string name);
	~City();
private:
	const std::string *const _name;
	const ResourceCreater *_resourceCreater{};
	const std::map<Resources, size_t> _resources{};
	const size_t _budget = 0;
};
