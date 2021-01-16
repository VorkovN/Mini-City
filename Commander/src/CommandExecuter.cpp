#include "CommandExecuter.h"
#include "BuildFactory.h"
#include "BuildStation.h"
#include "BuyTrain.h"
#include "SendTrain.h"
#include "Produice.h"
#include "ShowTrains.h"
#include "ShowFactories.h"
#include "ShowProducts.h"
#include "Help.h"
#include "Exit.h"


CommandExecuter::CommandExecuter()
{
	commands_map["help"] = new Help;
	commands_map["build_station"] = new BuildStation;//название
	commands_map["build_factory"] = new BuildFactory;//город, тип фабрики
	commands_map["buy_train"] = new BuyTrain;//город, кол-во вагонов
	commands_map["produce"] = new Produice;//город, тип продукта
	commands_map["send_train"] = new SendTrain;//откуда, куда, номер поезда
	commands_map["show_trains"] = new ShowTrains;//город
	commands_map["show_products"] = new ShowProducts;//город
	commands_map["show_factories"] = new ShowFactories;//город
	commands_map["exit"] = new Exit;
}

std::map<std::string, Command*> CommandExecuter::getCommands() const
{
	return commands_map;
}

