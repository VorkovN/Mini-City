#pragma once
#include "Command.h"
#include <iostream>
#include <sstream>
#include<vector>

class BuildCity : public Command
{
public:
	bool execute(std::vector<std::string> args_vector) const override;
};