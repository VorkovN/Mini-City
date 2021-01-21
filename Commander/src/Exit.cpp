#include "Exit.h"

bool Exit::execute()  const
{
	std::cout << "exit" << std::endl;
	exit(0);
}
