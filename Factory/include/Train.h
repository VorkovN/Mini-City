#pragma once
#include "CarsTypes.h"
#include "City.h"

class City;

class Train
{
 public:
	explicit Train(size_t cars_count, CarsTypes::Types cars_type);

	virtual void move(City* city1, City* city2, size_t cars_count) = 0;
	size_t& getCarsCount();
	CarsTypes::Types getCarsType();

 public:
	static std::map<CarsTypes::Types, size_t> car_price ;
 private:
	CarsTypes::Types _cars_type;
	size_t _cars_count;
};
