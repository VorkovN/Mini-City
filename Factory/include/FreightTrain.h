#pragma once
#include "CarsTypes.h"
#include "City.h"
#include "Train.h"

class FreightTrain : public Train
{
 public:
	FreightTrain(CarsTypes::Types cars_type, size_t cars_count);

	void move(City city1, City city2) override;
};
