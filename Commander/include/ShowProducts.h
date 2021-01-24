#pragma once
#include "Command.h"
#include <iostream>

class ShowProducts : public Command
{
public:
	bool execute(std::vector<std::string> args_vector) const override;
};
