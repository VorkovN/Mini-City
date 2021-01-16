#pragma once
#include "Command.h"
#include <iostream>

class BuildStation : public Command
{
public:
	bool execute() override;
};