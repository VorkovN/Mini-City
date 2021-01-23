#include "ResourcesTypes.h"

std::map<std::string, Resources::ResourcesTypes> const Resources::_resources = {{"ore", Resources::ORE},{"wood", Resources::WOOD},{"liquid", Resources::LIQUID}};

 Resources::ResourcesTypes Resources::getResourcesMap(const std::string& str)
{
	return _resources.at(str);//может вылететь эксепшен
}