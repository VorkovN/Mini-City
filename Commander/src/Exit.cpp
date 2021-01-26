#include "Exit.h"

bool Exit::execute()  const
{
	std::cerr << "Game over (exit command)" << std::endl;
	delete World::GetWorld();
	exit(0);
}
