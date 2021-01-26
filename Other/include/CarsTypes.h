#pragma once

#include <string>
#include <map>

class CarsTypes
{
 public:
	//к сожалению в с++ нет наследования enum, поэтому я не придумал ничего луче,
	//чем выразить общий класс как целые числа, а 2 типа наследников как отрицательные и неотрицательные числа
	enum Types
	{
		SIMPLE = -2,
		BILEVEL = -1,
		ORE = 0,
		WOOD = 1,
		LIQUID = 2,
	};

 private:
	static const std::map<std::string, Types> _resources;//карта перевода для ресурсных типов
	static const std::map<std::string, Types> _cars_types;//карта перевода для всех типов

 public:
	static Types getResurcesTypes(const std::string& str);//карта перевода для ресурсных типов
	static Types getCarTypes(const std::string& str);//карта перевода для всех типов

};

