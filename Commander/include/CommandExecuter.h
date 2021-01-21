#pragma once
#include <iostream>
#include <map>
#include "Command.h"

class CommandExecuter
{
private:
	const std::map<const std::string, const Command*> _commands_map;

public:
	CommandExecuter();

	[[nodiscard]] const std::map<const std::string, const Command*>& getCommands() const;
};

