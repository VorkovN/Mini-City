#include "PassengerTrain.h"

PassengerTrain::PassengerTrain(CarsTypes::Types cars_type, size_t cars_count) : Train(cars_count, cars_type)
{
	std::cout << "new passenger train" << std::endl;
}

void PassengerTrain::move(City* city_from, City* city_to, size_t cars_count)
{
	city_from->getRailwayStation()[getCarsType()].remove(this);
	if (getCarsType() == CarsTypes::BILEVEL)
		city_from->setPopulation(city_from->getPopulation() - 2 * cars_count);
	else
		city_from->setPopulation(city_from->getPopulation() - cars_count);
	std::cout << "train left from " << *city_from->getName() << std::endl;



	city_to->getRailwayStation()[getCarsType()].push_back(this);
	if (getCarsType() == CarsTypes::BILEVEL)
		city_to->setPopulation(city_to->getPopulation() + 2 * cars_count);
	else
		city_to->setPopulation(city_to->getPopulation() + cars_count);
	std::cout << "train arrived to " << *city_to->getName() << std::endl;

}
