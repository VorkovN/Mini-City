#include "PassengerTrainFactory.h"

Train* PassengerTrainFactory::createTrain(CarsTypes::Types type, size_t cars_count)
{
	return new PassengerTrain(type, cars_count);
}