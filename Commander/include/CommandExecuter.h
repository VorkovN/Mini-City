#pragma once
#include <iostream>
#include <map>
#include "Command.h"

class CommandExecuter
{
public:
	std::map<std::string, Command> commands_map;

public:
	CommandExecuter();
};

