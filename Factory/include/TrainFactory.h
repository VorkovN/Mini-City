#pragma once
#include "Train.h"

class City;
class Train;

class TrainFactory{
 public:
	virtual ~TrainFactory();
	virtual Train* createTrain(CarsTypes::Types, size_t cars_count) = 0;

 private:
	CarsTypes::Types _type;
};
