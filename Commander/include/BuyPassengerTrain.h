#pragma once
#include "Command.h"
#include <iostream>

class BuyPassengerTrain : public Command
{
 public:
	bool execute(std::vector<std::string> args_vector) const override;
};