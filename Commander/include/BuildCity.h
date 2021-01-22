#pragma once
#include "Command.h"
#include <iostream>
#include <sstream>

class BuildCity : public Command
{
public:
	bool execute(std::string city_name_str) const override;
};