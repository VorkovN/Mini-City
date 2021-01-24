#include "MaternityHospital.h"

void MatrinityHospital::createChildren()
{
	size_t i = 1000;
	while (true)
	{
		_city->getPopulation() += i++/1000;
		sleep(5);
	}
}

MatrinityHospital::MatrinityHospital(City* city): _city(city)
{
	std::thread func_thread(&MatrinityHospital::createChildren, this);
	func_thread.detach();
	std::cout << "new maternity hospital" << std::endl;
}

