#include "MaternityHospital.h"

MatrinityHospital::MatrinityHospital(City* city): _city(city)
{
	std::thread func_thread(&MatrinityHospital::createChildren, this);
	func_thread.detach();
	std::cout << "new maternity hospital" << std::endl;
}

void MatrinityHospital::createChildren()
{
	while (true)
	{
		_city->setPopulation(_city->getPopulation() + CREATE_CHILDREN++/1000);
		sleep(rand() % 5 + 1);
	}
}