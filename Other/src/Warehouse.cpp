#include "Warehouse.h"

Warehouse::Warehouse(City* city) : _city(city)
{
	//auto f1 = async(std::launch::async, &Warehouse::sellProduct<decltype(CarsTypes::ORE)>, this, CarsTypes::ORE);
	//auto f2 = async(std::launch::async, &Warehouse::sellProduct<decltype(CarsTypes::WOOD)>, this, CarsTypes::WOOD);
	//auto f3 = async(std::launch::async, &Warehouse::sellProduct<decltype(CarsTypes::LIQUID)>, this, CarsTypes::LIQUID);
	//std::cout << "new warehouse" << std::endl;
}

template<class T>
void Warehouse::sellProduct(T resource)
{
	std::cout << "sellProduct" << std::endl;
	size_t resource_count = 0;
	while (true)
	{
		_city->_mu.lock();
		std::cout << "-1" << resource << std::endl;
		resource_count = _city->_population;
		std::cout << "-2" << std::endl;
		if (SELL_PRODUCT/1000 > resource_count)
		resource_count -= SELL_PRODUCT++/1000;
		_city->_mu.unlock();
		sleep(rand() % 10 + 1);

	}
}

