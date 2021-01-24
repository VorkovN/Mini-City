#pragma once
#include "Train.h"


class TrainFactory{
 public:
	virtual Train* createTrain(CarsTypes::Types, size_t cars_count) = 0;

 private:
	CarsTypes::Types _type;
};
