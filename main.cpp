#include <iostream>
#include <vector>
#include "World.h"
#include "CommandExecuter.h"

int main()
{
	World* world = World::GetWorld();
	std::cout << "Input you command (command help can help you)" << std::endl;
	CommandExecuter commandExecuter;
	while (true)
	{
		std::string command_word, arg;
		std::vector<std::string> args_vector;
		std::cin >> command_word;

		const auto command = commandExecuter.getCommands().find(command_word);

		if (command != commandExecuter.getCommands().end())
		{
			while (std::cin.peek() != '\n')
			{
				std::cin >> arg;
				args_vector.push_back(arg);
			}

			if (args_vector.empty())
			{
				if (!command->second->execute())
					std::cout << "execute error" << std::endl;
			}

			else
			{
				if (!command->second->execute(args_vector))
					std::cout << "execute error" << std::endl;
			}

		}
		else
		{
			std::cout << "command type error" << std::endl;
		}
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
