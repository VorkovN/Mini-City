#include "Exit.h"
#include <exception>
#include <stdexcept>
bool Exit::execute()  const
{
	std::cout << "exit" << std::endl;
	throw "Game over(Exit command)";
}
