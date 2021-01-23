#include "ResourceFactory.h"

void ResourceFactory::resource_factory_working()
{
	while (true)
	{
		city->_resources[resource] += productivity;
		std::cout << "resource " << resource <<  " created" << std::endl;
		std::cout << "now: " << city->_resources[Resources::ORE] << ", " << city->_resources[Resources::WOOD] << ", " << city->_resources[Resources::LIQUID] << std::endl;
		sleep(10);
	}
}

ResourceFactory::ResourceFactory(Resources::ResourcesTypes resource, City* city) : city(city), resource(resource)
{
	std::thread func_thread(&ResourceFactory::resource_factory_working, this);
	func_thread.detach();
	std::cout << "new factory" << std::endl;
};

