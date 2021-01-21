#pragma once
#include "Command.h"
#include <iostream>

class ShowFactories : public Command
{
public:
	bool execute() const override;
};
