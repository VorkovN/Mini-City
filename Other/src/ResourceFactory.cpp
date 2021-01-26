#include "ResourceFactory.h"
#include "World.h"

ResourceFactory::ResourceFactory(CarsTypes::Types resource, City& city) : _city(city), _resource(resource)
{
	std::thread func_thread(&ResourceFactory::resource_factory_working, this);
	func_thread.detach();
	std::cout << "new factory" << std::endl;
}

void ResourceFactory::resource_factory_working()
{
	while (true)
	{
		_city.getMutex().lock();
		_city.getResources()[_resource] += _productivity;
		_city.getMutex().unlock();
		if (!World::ALIVE_WORLD)
			break;
		sleep(rand() % 3 + 1);
	}
}

CarsTypes::Types ResourceFactory::getResource() const
{
	return _resource;
};

