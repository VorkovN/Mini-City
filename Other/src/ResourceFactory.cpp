#include "ResourceFactory.h"

void ResourceFactory::resource_factory_working()
{
	while (true)
	{
		city->getResources()[resource] += productivity;
		std::cout << "resource " << resource <<  " created" << std::endl;
		std::cout << "now: " << city->getResources()[CarsTypes::ORE] << ", " << city->getResources()[CarsTypes::WOOD] << ", " << city->getResources()[CarsTypes::LIQUID] << std::endl;
		sleep(10);
	}
}

ResourceFactory::ResourceFactory(CarsTypes::Types resource, City* city) : city(city), resource(resource)
{
	std::thread func_thread(&ResourceFactory::resource_factory_working, this);
	func_thread.detach();
	std::cout << "new factory" << std::endl;
};

