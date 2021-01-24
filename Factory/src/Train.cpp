#include "Train.h"

Train::Train(size_t cars_count, CarsTypes::Types cars_type):_cars_count(cars_count), _cars_type(cars_type){}

size_t& Train::getCarsCount()
{
	return _cars_count;
};

CarsTypes::Types Train::getCarsType()
{
	return _cars_type;
}
