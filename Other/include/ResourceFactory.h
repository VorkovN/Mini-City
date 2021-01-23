#pragma once
#include <iostream>
#include <unistd.h>
#include "ResourcesTypes.h"
#include "City.h"

class City;

class ResourceFactory
{
 public:
	ResourceFactory(Resources::ResourcesTypes resource, City *city);

 private:
	City *city = nullptr;
	Resources::ResourcesTypes resource = Resources::ORE;
	size_t productivity = 1; //how mach resources created for one cicle

 private:
	void resource_factory_working();
};
