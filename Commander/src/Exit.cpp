#include "Exit.h"

bool Exit::execute()  const
{
	std::cerr << "Game over (exit command)" << std::endl;
	World::ALIVE_WORLD = false;
}
