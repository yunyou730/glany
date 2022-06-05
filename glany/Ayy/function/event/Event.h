#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "function/scene_management/entity/Entity.h"

NS_AYY_BEGIN

class Event
{
public:
	virtual ~Event() {}
};

class CreateEntityEvent : public Event
{

};

class DeleteEntityEvent : public Event
{
public:
	DeleteEntityEvent(EntityID entityId)
		:_entityId(entityId)
	{
	}

	EntityID	_entityId = 0;
};


NS_AYY_END
