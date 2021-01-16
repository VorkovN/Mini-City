#include "Exit.h"

bool Exit::execute()
{
	std::cout << "exit" << std::endl;
	exit(0);
}
