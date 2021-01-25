#include "CarsTypes.h"

std::map<std::string, CarsTypes::Types> const CarsTypes::_resources = {{"ore", CarsTypes::ORE},{"wood", CarsTypes::WOOD},{"liquid", CarsTypes::LIQUID}};

 CarsTypes::Types CarsTypes::getResurcesTypes(const std::string& str)
{
	return _resources.at(str);//может вылететь эксепшен
}

std::map<std::string, CarsTypes::Types> const CarsTypes::_cars_types = {{"simple", CarsTypes::SIMPLE},{"bilevel", Types::BILEVEL},{"ore", CarsTypes::ORE},{"wood", CarsTypes::WOOD},{"liquid", CarsTypes::LIQUID}};

CarsTypes::Types CarsTypes::getCarTypes(const std::string& str)
{
	return _cars_types.at(str);//может вылететь эксепшен
}