#pragma once
#include "World.h"

class Command
{
public:
	virtual bool execute() const;
	virtual bool execute(std::string agrs) const;
protected:
	World *_world = World::GetWorld();
};
