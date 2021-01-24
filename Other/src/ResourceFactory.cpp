#include "ResourceFactory.h"

void ResourceFactory::resource_factory_working()
{
	while (true)
	{
		_city->getResources()[_resource] += _productivity;
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

