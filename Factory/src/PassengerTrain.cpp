#include "PassengerTrain.h"

PassengerTrain::PassengerTrain(CarsTypes::Types cars_type, size_t cars_count) : Train(cars_count, cars_type)
{
	std::cout << "new passenger train" << std::endl;
}

void PassengerTrain::move(City* city_from, City* city_to)
{
	city_from->getRailwayStation()[getCarsType()].remove(this);
	if (getCarsType() == CarsTypes::BILEVEL)
		city_from->getPopulation() -= 2 * getCarsCount();
	else
		city_from->getPopulation() -= getCarsCount();
	std::cout << "train left from " << *city_from->getName() << std::endl;



	city_to->getRailwayStation()[getCarsType()].push_back(this);
	if (getCarsType() == CarsTypes::BILEVEL)
		city_to->getPopulation() += 2 * getCarsCount();
	else
		city_to->getPopulation() += getCarsCount();
	std::cout << "train arrived to " << *city_to->getName() << std::endl;

}
