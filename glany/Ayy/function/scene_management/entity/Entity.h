#pragma once

#include "core/util_func.h"
#include <map>
#include <string>
#include "function/scene_management/component/BaseComponent.h"

NS_AYY_BEGIN

using EntityID = unsigned int;

class Entity
{
public:
	Entity(EntityID entityId);
	~Entity();

	EntityID GetID() const { return _entityId; }

	void AddComponent(const std::string& clsName,BaseComponent* component);

protected:
	EntityID  _entityId = 0;
	std::map<std::string, BaseComponent*>	_componentMap;
};

NS_AYY_END

