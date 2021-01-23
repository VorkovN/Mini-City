#pragma once
#include "Resources.h"

class Train
{
 public:
	Train(Resources::ResourcesTypes cars_type, size_t cars_count);

 public://todo закрытьпосле отладки
	Resources::ResourcesTypes _cars_types;
	size_t _cars_count;
};
