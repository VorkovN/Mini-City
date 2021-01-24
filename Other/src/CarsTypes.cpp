#include "CarsTypes.h"

std::map<std::string, CarsTypes::Types> const CarsTypes::_resources = {{"ore", CarsTypes::ORE},{"wood", CarsTypes::WOOD},{"liquid", CarsTypes::LIQUID}};

 CarsTypes::Types CarsTypes::getFrCarTypes(const std::string& str)
{
	return _resources.at(str);//может вылететь эксепшен
}

std::map<std::string, CarsTypes::Types> const CarsTypes::_passenger_cars_types
		= {{"simple", CarsTypes::SIMPLE},{"bilevel", Types::BILEVEL}};


CarsTypes::Types CarsTypes::getPasCarTypes(const std::string& str)
{
	return _passenger_cars_types.at(str);
}