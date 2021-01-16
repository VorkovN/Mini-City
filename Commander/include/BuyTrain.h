#pragma once
#include "Command.h"
#include <iostream>

class BuyTrain : public Command
{
public:
	bool execute() override;
};
