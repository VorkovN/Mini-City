#include "ResourceFactory.h"

void ResourceFactory::resource_factory_working()
{
	while (true)
	{
		_city->getResources()[_resource] += _productivity;
		std::cout << "_resource " << _resource << " created" << std::endl;
		std::cout << "now: " << _city->getResources()[CarsTypes::ORE] << ", " << _city->getResources()[CarsTypes::WOOD] << ", " << _city->getResources()[CarsTypes::LIQUID] << std::endl;
		sleep(10);
	}
}

ResourceFactory::ResourceFactory(CarsTypes::Types resource, City* city) : _city(city), _resource(resource)
{
	std::thread func_thread(&ResourceFactory::resource_factory_working, this);
	func_thread.detach();
	std::cout << "new factory" << std::endl;
}

CarsTypes::Types ResourceFactory::getResource() const
{
	return _resource;
};

