#pragma once
#include "Command.h"
#include <iostream>

class ShowTrains : public Command
{
public:
	bool execute() override;
};
