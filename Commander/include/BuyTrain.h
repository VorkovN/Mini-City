#pragma once
#include "Command.h"
#include "CarsTypes.h"
#include <iostream>

class BuyTrain : public Command
{
public:
	bool execute(std::vector<std::string> args_vector) const override;
};
