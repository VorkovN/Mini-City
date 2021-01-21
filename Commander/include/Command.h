#pragma once
#include "World.h"

class Command
{
public:
	virtual bool execute() const = 0;
protected:
	World *_world = nullptr;
};
