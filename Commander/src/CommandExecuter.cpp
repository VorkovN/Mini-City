#include "CommandExecuter.h"

CommandExecuter::CommandExecuter()
{
	commands_map["help"];//0 arg
	commands_map["build_shop"];//1 arg
	commands_map["build_factory"];//1 arg
	commands_map["buy"];//2 arg
	commands_map["produce"];//2 arg
	commands_map["deliver"];//4 arg
	commands_map["exit"];//0 arg
}

