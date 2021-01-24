#include "FreightTrainFactory.h"

Train* FreightTrainFactory::createTrain(CarsTypes::Types type, size_t cars_count)
{
	return new FreightTrain(type, cars_count);
}


