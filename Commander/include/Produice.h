#pragma once
#include "Command.h"
#include <iostream>

class Produice : public Command
{
public:
	bool execute() const override;
};
