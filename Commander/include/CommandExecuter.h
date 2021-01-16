#pragma once
#include <iostream>
#include <map>
#include "Command.h"

class CommandExecuter
{
private:
	std::map<std::string, Command*> commands_map;

public:
	CommandExecuter();

	std::map<std::string, Command*> getCommands() const;
};

