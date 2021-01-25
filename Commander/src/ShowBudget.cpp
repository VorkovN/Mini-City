#include "ShowBudget.h"


bool ShowBudget::execute()  const
{
	if(!_world->showBudget())
		return false;
	return true;
}