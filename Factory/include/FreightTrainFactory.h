#pragma once

#include "TrainFactory.h"
#include "FreightTrain.h"

class FreightTrainFactory : public TrainFactory
{
 public:
	Train* createTrain(CarsTypes::Types type, size_t cars_count) override;

};
