#pragma once
#include "Command.h"
#include <iostream>

class Help : public Command
{
public:
	bool execute() const override;
};
