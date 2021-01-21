#pragma once
#include "Command.h"
#include <iostream>

class SendTrain : public Command
{
public:
	bool execute() const override;
};