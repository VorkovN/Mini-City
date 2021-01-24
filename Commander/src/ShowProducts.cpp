#include "ShowProducts.h"

bool ShowProducts::execute(std::vector<std::string> args_vector)  const
{
	if(!_world->showProducts(args_vector[0]))
		return false;
	return true;
}
