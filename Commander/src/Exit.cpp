#include "Exit.h"

bool Exit::execute()  const
{
	std::cout << "Game over (exit command)" << std::endl;
	std::cerr << "Game over (exit command)" << std::endl;
	World::ALIVE_WORLD = false;
}
