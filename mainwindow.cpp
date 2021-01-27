#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "World.h"
#include <iostream>

bool MainWindow::flag = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
	  _timer(new QTimer()),
	  _world(World::getCreatedWorld())
{
    ui->setupUi(this);
	std::cout.rdbuf( oss.rdbuf());
	std::cerr.rdbuf( oss.rdbuf());
    ui->inputField->setText("Input you command");

	connect(_timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
	_timer->start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_executeButton_clicked()
{
    _command_str = ui->inputField->text();
}

void MainWindow::slotTimerAlarm()
{
	if (!World::ALIVE_WORLD)
	{
		_timer->stop();
		sleep(8);
		delete World::getCreatedWorld();
	}

	std::string command_word = "", arg = "";
	std::vector<std::string> args_vector;

	if(_command_str.toStdString() != "")
	{
		std::cout << std::endl;

		std::istringstream sstr(_command_str.toStdString());

		sstr >> command_word;

		const auto command = _commandExecuter.getCommands().find(command_word);

		if (command != _commandExecuter.getCommands().end())
		{
			while (sstr.peek() != '\n' && !sstr.eof())
			{
				sstr >> arg;
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
	ui->textEdit->setText(QString::fromStdString(oss.str()));
	_command_str = "";
}

