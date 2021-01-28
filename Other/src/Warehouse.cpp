#include "Warehouse.h"
#include "World.h"

Warehouse::Warehouse(City& city) : _city(city)
{
	std::thread(&Warehouse::sellProduct<decltype(CarsTypes::ORE)>, this, CarsTypes::ORE).detach();
	std::thread(&Warehouse::sellProduct<decltype(CarsTypes::WOOD)>, this, CarsTypes::WOOD).detach();
	std::thread(&Warehouse::sellProduct<decltype(CarsTypes::LIQUID)>, this, CarsTypes::LIQUID).detach();

	std::cout << "new warehouse" << std::endl;
}

template<class T>
void Warehouse::sellProduct(T resource)
{
	_city.getMutex().lock();
	std::cout << "sellProduct" << std::endl;
	size_t sold_products;
	_city.getMutex().unlock();
	while (true)
	{
		_city.getMutex().lock();
		size_t &resource_count = _city.getResources()[resource];
		sold_products = _city.getPopulation()/SELLING_K + 1;
		_city.getMutex().unlock();
		if (sold_products > resource_count)
		{
			std::cout << "GAME OVER (resource " + std::to_string(resource) + " run out)" ;
			World::ALIVE_WORLD = false;
			break;
		}
		_city.getMutex().lock();
		resource_count -= sold_products;
		_city.setBudget(_city.getBudget() + sold_products);
		_city.getMutex().unlock();
		if (!World::ALIVE_WORLD)
			break;
		sleep(rand() % 6 + 1);
	}
	_city.getMutex().lock();
	std::cout << "Warehouse thread destroyed" << std::endl;
	_city.getMutex().unlock();
}

