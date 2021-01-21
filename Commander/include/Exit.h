#pragma once
#include "Command.h"
#include <iostream>

class Exit : public Command
{
public:
	bool execute() const override;
};