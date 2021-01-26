#include "Exit.h"

bool Exit::execute()  const
{
	std::cerr << "Game over (exit command)" << std::endl;
	World::ALIVE_WORLD = false;
	sleep(8);
	delete World::getCreatedWorld();
	exit(0);
}
