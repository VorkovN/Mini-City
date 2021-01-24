#pragma once
#include <iostream>
#include <unistd.h>
#include "CarsTypes.h"
#include "City.h"

class City;

class ResourceFactory
{
 public:
	ResourceFactory(CarsTypes::Types resource, City *city);

 private:
	City *city = nullptr;
	CarsTypes::Types resource = CarsTypes::ORE;
	size_t productivity = 1; //how mach resources created for one cicle

 private:
	void resource_factory_working();
};
