#include "PassengerTrain.h"

PassengerTrain::PassengerTrain(CarsTypes::Types cars_type, size_t cars_count): Train(cars_count, cars_type){}

void PassengerTrain::move(City city_from, City city_to)
{
	city_from.getRailwayStation().remove(this);
	city_to.getRailwayStation().push_back(this);

	if (getCarsType() == CarsTypes::BILEVEL)
	{
		city_from.getPopulation() -= 2*getCarsCount();
		city_to.getPopulation() += 2*getCarsCount();
	}
	else
	{
		city_from.getPopulation() -= getCarsCount();
		city_to.getPopulation() += getCarsCount();
	}

}
