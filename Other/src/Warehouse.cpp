#include "Warehouse.h"
#include "World.h"

Warehouse::Warehouse(City& city) : _city(city)
{
	std::thread f1(&Warehouse::sellProduct<decltype(CarsTypes::ORE)>, this, CarsTypes::ORE);
	std::thread f2(&Warehouse::sellProduct<decltype(CarsTypes::WOOD)>, this, CarsTypes::WOOD);
	std::thread f3(&Warehouse::sellProduct<decltype(CarsTypes::LIQUID)>, this, CarsTypes::LIQUID);
	f1.detach();
	f2.detach();
	f3.detach();

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
		if (sold_products > resource_count)
		{
			std::cerr << "Game over (resource " + std::to_string(resource) + " run out)" ;
			World::ALIVE_WORLD = false;
			sleep(8);
			delete World::getCreatedWorld();
			exit(0);
		}

		resource_count -= sold_products;
		_city.setBudget(_city.getBudget() + sold_products);
		_city.getMutex().unlock();
		if (!World::ALIVE_WORLD)
			break;
		sleep(rand() % 6 + 1);
	}
}

