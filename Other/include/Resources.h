#pragma once
#include <string>
#include <map>

class Resources{
 public:
	enum ResourcesTypes
	{
		ORE = 0,
		WOOD = 1,
		LIQUID = 2
	};
 private:
	static const std::map<std::string, ResourcesTypes> _resources;

 public:
	static ResourcesTypes getResourcesMap(const std::string& str);

};

