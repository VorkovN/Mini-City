#include "Train.h"

std::map<CarsTypes::Types, size_t> Train::car_price = {{CarsTypes::SIMPLE, 5},{CarsTypes::BILEVEL, 9},{CarsTypes::ORE, 6},{CarsTypes::WOOD, 6},{CarsTypes::LIQUID, 6}};


Train::Train(size_t cars_count, CarsTypes::Types cars_type):_cars_count(cars_count), _cars_type(cars_type){}

size_t& Train::getCarsCount()
{
	return _cars_count;
};

CarsTypes::Types Train::getCarsType()
{
	return _cars_type;
}

