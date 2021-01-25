#pragma once

#include <string>
#include <map>

class CarsTypes
{
 public:
	enum Types//todo поправить костыль
	{
		SIMPLE = -2,
		BILEVEL = -1,
		ORE = 0,
		WOOD = 1,
		LIQUID = 2,

	};

 private:
	static const std::map<std::string, Types> _resources;
	static const std::map<std::string, Types> _cars_types;

 public:
	static Types getResurcesTypes(const std::string& str);
	static Types getCarTypes(const std::string& str);

};

