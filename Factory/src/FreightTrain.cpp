#include "FreightTrain.h"

FreightTrain::FreightTrain(CarsTypes::Types cars_type, size_t cars_count): Train(cars_count, cars_type){}

void FreightTrain::move(City* city_from, City* city_to)
{
	city_from->getRailwayStation()[getCarsType()].remove(this);
	city_to->getRailwayStation()[getCarsType()].push_back(this);

	city_from->getResources()[getCarsType()] -= getCarsCount();
	city_to->getResources()[getCarsType()] += getCarsCount();
}
