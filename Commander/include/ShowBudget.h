#pragma once
#include "Command.h"
#include <iostream>

class ShowBudget : public Command
{
 public:
	bool execute() const override;
};
