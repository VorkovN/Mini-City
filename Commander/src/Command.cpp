#include "Command.h"

bool Command::execute() const
{
	std::cout << "This command requires args" << std::endl;
	return true;
}

bool Command::execute(std::vector<std::string> agrs) const
{
	std::cout << "This command doesn't requires args" << std::endl;
	return true;
}
