#include "Help.h"

bool Help::execute()  const
{
	std::cout << "help - show all commands" << std::endl;
	std::cout << "build_city - to build new city" << std::endl;
	std::cout << "build_factory - to build factory on factory" << std::endl;
	std::cout << "buy_train - to buy new train" << std::endl;
	std::cout << "send_train - to send train to same city" << std::endl;
	std::cout << "show_trains - show train on station" << std::endl;
	std::cout << "show_products - show products on station" << std::endl;
	std::cout << "show_factories - show factories on station" << std::endl;
	std::cout << "exit - game over" << std::endl;
	return true;
}
