#pragma once
#include "Command.h"
#include <iostream>

class BuildFactory : public Command
{
public:
	bool execute() override;
};