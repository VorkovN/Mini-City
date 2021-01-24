#pragma once

#include <string>
#include <map>

class CarsTypes
{
 public:
	enum Types
	{
		SIMPLE = -2,
		BILEVEL = -1,
		ORE = 0,
		WOOD = 1,
		LIQUID = 2,

	};

 private:
	static const std::map<std::string, Types> _resources;
	static const std::map<std::string, Types> _passenger_cars_types;

 public:
	static Types getFrCarTypes(const std::string& str);
	static Types getPasCarTypes(const std::string& str);

};

