#pragma once
#include "World.h"
#include <vector>

class Command
{
public:
	virtual bool execute() const;
	virtual bool execute(std::vector<std::string> agrs_vector) const;
protected:
	World *_world = World::GetWorld();
};
