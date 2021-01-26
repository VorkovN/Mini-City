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
	size_t SELLING_K = 100;
	City* _city = nullptr;
};