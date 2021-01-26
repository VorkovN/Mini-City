#include "MaternityHospital.h"
#include "World.h"

MatrinityHospital::MatrinityHospital(City& city): _city(city)
{
	std::thread func_thread(&MatrinityHospital::createChildren, this);
	func_thread.detach();
	std::cout << "new maternity hospital" << std::endl;
}

void MatrinityHospital::createChildren()
{
	while (true)
	{
		_city.setPopulation(_city.getPopulation() + CREATE_CHILDREN++/1000);
		if (!World::ALIVE_WORLD)
			break;
		sleep(rand() % 4 + 1);
	}
}
