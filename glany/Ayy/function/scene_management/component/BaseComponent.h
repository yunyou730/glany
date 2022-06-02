#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include <string>

NS_AYY_BEGIN

class Entity;
class BaseComponent
{
public:
	BaseComponent(Entity* entity);
	virtual ~BaseComponent();
	
	Entity* GetEntity() { return _entity; }

protected:
	Entity* _entity = nullptr;
};

NS_AYY_END
