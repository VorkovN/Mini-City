#include "FreightTrain.h"

FreightTrain::FreightTrain(CarsTypes::Types cars_type, size_t cars_count): Train(cars_count, cars_type)
{
	std::cout << "new freight train" << std::endl;
}

void FreightTrain::move(City* city_from, City* city_to, size_t cars_count)
{
	city_from->getRailwayStation()[getCarsType()].remove(this);
	city_from->getResources()[getCarsType()] -= cars_count;
	std::cout << "train left from " << *city_from->getName() << std::endl;

	city_to->getRailwayStation()[getCarsType()].push_back(this);
	city_to->getResources()[getCarsType()] += cars_count;
	std::cout << "train arrived to " << *city_to->getName() << std::endl;
}
