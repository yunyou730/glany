#pragma once

#include "core/util_func.h"
#include <vector>
#include "function/event/Event.h"

NS_AYY_EDITOR_BEGIN

class SelectEntityInHierarchy: public Event
{
public:
	SelectEntityInHierarchy(EntityID entityId)
		:_entityId(entityId)
	{
	}

	EntityID	_entityId = 0;
};

NS_AYY_EDITOR_END
