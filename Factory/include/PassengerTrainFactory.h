#pragma once

#include "TrainFactory.h"
#include "PassengerTrain.h"


class PassengerTrainFactory : public TrainFactory
{
 public:
	Train* createTrain(CarsTypes::Types type, size_t cars_count) override;
};
