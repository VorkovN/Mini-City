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
	CarsTypes::Types getResource() const;

 private:
	City *_city = nullptr;
	CarsTypes::Types _resource;
	size_t _productivity = 1; //how mach resources created for one cicle

 private:
	void resource_factory_working();
};
