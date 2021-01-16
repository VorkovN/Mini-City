#pragma once
#include "Command.h"
#include <iostream>

class ShowProducts : public Command
{
public:
	bool execute() override;
};
