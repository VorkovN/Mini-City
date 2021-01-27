#include "BuyTrain.h"

bool BuyTrain::execute(std::vector<std::string> args_vector) const
{
	if (args_vector.size() != 3)
	{
		std::cerr << "wrong count of arguments, required: (city name, car type, cars count)" << std::endl;
		return false;
	}
	if(!_world->buyTrain(args_vector[0], CarsTypes::getCarTypes(args_vector[1]), stoi(args_vector[2])))
		return false;
	return true;
}