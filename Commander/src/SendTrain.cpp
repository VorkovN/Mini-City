#include "SendTrain.h"

bool SendTrain::execute(std::vector<std::string> args_vector)  const
{
	if (args_vector.size() != 4)
	{
		std::cerr << "wrong count of arguments, required: (city name1, city name2, car type, cars count)" << std::endl;
		return false;
	}

	if(!_world->sendTrain(args_vector[0], args_vector[1], CarsTypes::getCarTypes(args_vector[2]), stoi(args_vector[3])))
		return false;
	return true;
}