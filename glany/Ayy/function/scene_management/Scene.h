#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "function/scene_management/entity/Entity.h"

#include <map>
#include <vector>

NS_AYY_BEGIN

class Scene
{
public:
	Scene();
	~Scene();

	void Initialize();
	void Deinitialize();
	void Tick();

	Entity* CreateEntity();
	void DestroyEntity(EntityID entityId);
	
	template<typename... ComponentTypes>
	std::vector<Entity*> QueryEntity()
	{
		std::vector<Entity*> result;
		for (auto it : _entityMap)
		{
			Entity* entity = it.second;
			if (entity->HasComponent<ComponentTypes...>())
			{
				result.push_back(entity);
			}
		}
		return result;
	}

	std::map<EntityID, Entity*>& GetEntityMap() { return _entityMap; }
	
protected:
	EntityID AllocateEntityID();

protected:
	std::map<EntityID, Entity*> _entityMap;

	EntityID	_entityIdSeed = 0;
};

NS_AYY_END
