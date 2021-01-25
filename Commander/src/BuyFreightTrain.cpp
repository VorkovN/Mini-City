#include "BuyFreightTrain.h"

bool BuyFreightTrain::execute(std::vector<std::string> args_vector) const
{
	if (args_vector.size() != 3)
		return false;
	if(!_world->buyFreightTrain(args_vector[0], CarsTypes::getResurcesTypes(args_vector[1]), stoi(args_vector[2])))
		return false;
	return true;
}