#pragma once
#include <exception>
#include "World.h"

class Command
{
public:
	virtual bool execute() const;
	virtual bool execute(std::vector<std::string> agrs_vector) const;
protected:
	World *_world = World::getCreatedWorld();
};
