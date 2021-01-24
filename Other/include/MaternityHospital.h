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
	City* _city = nullptr;
};
