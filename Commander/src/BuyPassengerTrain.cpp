#include "BuyPassengerTrain.h"

bool BuyPassengerTrain::execute(std::vector<std::string> args_vector) const
{
	if (args_vector.size() != 3)
		return false;
	if(!_world->buyPassengerTrain(args_vector[0], CarsTypes::getPasCarTypes(args_vector[1]), stoi(args_vector[2])))
		return false;
	return true;
}