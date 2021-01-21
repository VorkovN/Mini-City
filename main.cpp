#include <iostream>
#include "World.h"
#include "CommandExecuter.h"

int main()
{
	//World world = new World();
	std::cout << "Input you command (command help can help you)" << std::endl;
	CommandExecuter commandExecuter;
	while (true) {
		std::string command_str, arg;
		std::cin >> command_str;
		const std::_Rb_tree_const_iterator<std::pair<const std::basic_string<char,
		std::char_traits<char>,std::allocator<char>>, const Command *>>
		command = commandExecuter.getCommands().find(command_str);
		commandExecuter.getCommands();
		commandExecuter.getCommands();
		commandExecuter.getCommands();
		//if(command != commandExecuter.getCommands().end())
		command->second->execute();
		//else
		std::cout << "execute error";
	}
	return 0;
}


/**
есть возможность создавать города,
в каждом городе есть завод,
в каждом городе может быть только один завод,
завод автоматически генерируется при строительстве города,
заводы производят продукт,
потребитель запрашивает продукт на складе,
склад автоматически генерируется при строительстве города,
если есть, потребитель покупает продукт, если нет, то игра заканчивается,
за покупку продукта у города увеличивается бюджет,
этот бюджет можно тратить на покупку товарных поездов,
поезда можно покупать разных типов,
разные типы поездов перевозят разные типы ресурсов,
необходимо следить за наличием товара  на складе
**/
