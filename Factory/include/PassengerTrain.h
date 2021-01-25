#pragma once
#include "CarsTypes.h"
#include "City.h"


class PassengerTrain : public Train
{
 public:
	explicit PassengerTrain(CarsTypes::Types cars_type ,size_t cars_count);

	void move(City* city1, City* city2, size_t cars_count) override;
};
