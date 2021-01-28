#include "Train.h"

std::map<CarsTypes::Types, size_t> Train::car_price = {{CarsTypes::SIMPLE, 6},{CarsTypes::BILEVEL, 10},{CarsTypes::ORE, 8},{CarsTypes::WOOD, 8},{CarsTypes::LIQUID, 8}};


Train::Train(size_t cars_count, CarsTypes::Types cars_type):_cars_count(cars_count), _cars_type(cars_type){}

size_t& Train::getCarsCount()
{
	return _cars_count;
};

CarsTypes::Types Train::getCarsType()
{
	return _cars_type;
}

bool Train::operator==(const Train& train2) const {
	return (this->_cars_count == train2._cars_count);
}

bool Train::operator!=(const Train& train2) const {
	return (this->_cars_count != train2._cars_count);
}

bool Train::operator<(const Train& train2) const {
	return (this->_cars_count < train2._cars_count);
}

bool Train::operator>(const Train& train2) const {
	return (this->_cars_count > train2._cars_count);
}

bool Train::operator<=(const Train& train2) const {
	return (this->_cars_count <= train2._cars_count);
}

bool Train::operator>=(const Train& train2) const {
	return (this->_cars_count >= train2._cars_count);
}


