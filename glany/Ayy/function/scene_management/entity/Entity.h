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
	
	template<typename CompCls>
	CompCls* AddComponent()
	{
		auto comp = new CompCls(this);
		_componentMap.insert(std::make_pair(CompCls::ClsName(), comp));
		return comp;
	}
	
	template<typename ComponentType>
	bool HasComponent()
	{
		return _componentMap.find(ComponentType::ClsName()) != _componentMap.end();
	}


	template<typename ComponentType1,typename ComponentType2, typename... ComponentTypes>
	bool HasComponent()
	{
		if (!HasComponent<ComponentType1>())
		{
			return false;
		}
		return HasComponent<ComponentType2, ComponentTypes...>();
	}	

protected:
	EntityID  _entityId = 0;
	std::map<std::string, BaseComponent*>	_componentMap;
};

NS_AYY_END

