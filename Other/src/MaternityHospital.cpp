#include "MaternityHospital.h"
#include "World.h"

MatrinityHospital::MatrinityHospital(City& city): _city(city)
{
	std::thread(&MatrinityHospital::createChildren, this).detach();

	std::cout << "new maternity hospital" << std::endl;
}

void MatrinityHospital::createChildren()
{
	while (true)
	{
		_city.getMutex().lock();
		_city.setPopulation(_city.getPopulation() + CREATE_CHILDREN++/1000);
		_city.getMutex().unlock();
		if (!World::ALIVE_WORLD)
			break;
		sleep(rand() % 4 + 1);
	}
	_city.getMutex().lock();
	std::cout << "Meternity house thread destroyed" << std::endl;
	_city.getMutex().unlock();
}
