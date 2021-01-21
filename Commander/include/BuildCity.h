#pragma once
#include "Command.h"
#include <iostream>

class BuildCity : public Command
{
public:
	bool execute() const override;
};