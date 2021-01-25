#pragma once
#include <thread>
#include "City.h"

class City;

class MatrinityHospital
{
 public:
	MatrinityHospital(City *city);

 private:
	void createChildren();

 private:
	size_t CREATE_CHILDREN = 1000;
	City* _city = nullptr;
};
