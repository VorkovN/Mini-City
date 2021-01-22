#include "Command.h"

bool Command::execute() const
{
	std::cout << "This command requires args" << std::endl;
}

bool Command::execute(std::string agrs) const
{
	std::cout << "This command doesn't requires args" << std::endl;
}
