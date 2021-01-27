#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "World.h"
#include "CommandExecuter.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_executeButton_clicked()
{

    QString command_str = ui->inputField->text();
    ui->outputField->setText(command_str);
}

bool MainWindow::loop()
{
	std::cout << "lol" << std::endl;
	srand(time(nullptr));
	World* world = World::getCreatedWorld();
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

		if (!World::ALIVE_WORLD)
			break;
		//sleep(1);
		usleep(100000);//требуется для корректонй инициализации объектов в нескольких потоках
	}
	sleep(5);
	delete World::getCreatedWorld();
	return false;
}
