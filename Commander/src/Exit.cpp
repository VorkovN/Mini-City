#include "Exit.h"

bool Exit::execute()  const
{
	std::cerr << "GAME OVER (exit command)" << std::endl;
	World::ALIVE_WORLD = false;
}
