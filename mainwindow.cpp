#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "World.h"
#include "CommandExecuter.h"
#include <iostream>
#include <sstream>

bool MainWindow::flag = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->inputField->setText("Input you command (command help can help you)");

	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
	timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_executeButton_clicked()
{

    _command_str = ui->inputField->text();
	std::cout.rdbuf( oss.rdbuf() );

}

void MainWindow::slotTimerAlarm()
{
	std::string command_word = "", arg = "";
	std::vector<std::string> args_vector;

	if(_command_str.toStdString() != "")
	{
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
	ui->outputField->setText(QString::fromStdString(oss.str()));
	_command_str = "";
}

