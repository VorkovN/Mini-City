#pragma once
#include "Command.h"
#include <iostream>

class ShowPopulation : public Command
{
public:
	bool execute() const override;
};
