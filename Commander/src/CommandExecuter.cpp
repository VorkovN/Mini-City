#include "CommandExecuter.h"
#include "BuildFactory.h"
#include "BuildCity.h"
#include "BuyTrain.h"
#include "SendTrain.h"
#include "ShowPopulation.h"
#include "ShowTrains.h"
#include "ShowFactories.h"
#include "ShowProducts.h"
#include "ShowBudget.h"
#include "SellTrain.h"
#include "Help.h"
#include "Exit.h"


CommandExecuter::CommandExecuter(): _commands_map({
					  {"help", new Help},
					  {"build_city", new BuildCity},//название, тип фабрики
					  {"build_factory", new BuildFactory},//город, тип фабрики
					  {"buy_train", new BuyTrain},//город, тип, кол-во вагонов
					  {"sell_train", new SellTrain},//город, тип, кол-во вагонов
					  {"show_population", new ShowPopulation},//город, тип продукта
					  {"show_budget", new ShowBudget},//город, тип продукта
					  {"send_train", new SendTrain},//откуда, куда, номер поезда
					  {"show_trains", new ShowTrains},//город
					  {"show_products", new ShowProducts},//город
					  {"show_factories", new ShowFactories},//город
					  {"exit", new Exit}})
{};

const std::map<const std::string, const Command *>& CommandExecuter::getCommands() const
{
	return _commands_map;
}

