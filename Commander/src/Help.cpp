#include "Help.h"

bool Help::execute()  const
{
	std::cout << "help - show all commands" << std::endl;
	std::cout << "build_city - to build new city(name, factory type)" << std::endl;
	std::cout << "build_factory - to build factory on factory" << std::endl;
	std::cout << "buy_passenger_train - to buy new passenger train (city name, car type, cars count)" << std::endl;
	std::cout << "buy_freight_train - to buy new freight train (city name, car type, cars count)" << std::endl;
	std::cout << "send_train - to send train to same city" << std::endl;
	std::cout << "show_trains - show train on station" << std::endl;
	std::cout << "show_products - show products on station" << std::endl;
	std::cout << "show_factories - show factories on station" << std::endl;
	std::cout << "exit - game over" << std::endl;
	std::cout << "passenger car types: bilevel, simple" << std::endl;
	std::cout << "freight car types: ore, wood, liquid" << std::endl;
	return true;
}
