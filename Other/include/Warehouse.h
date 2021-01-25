#pragma once
#include <thread>
#include <random>
#include <future>
#include <chrono>
#include "City.h"

class City;

class Warehouse
{
 public:
	Warehouse(City *city);

 private:
	template<class T>
	void sellProduct(T resource);

 private:
	size_t SELL_PRODUCT = 1000;
	City* _city = nullptr;
};