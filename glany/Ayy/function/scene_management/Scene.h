#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "function/scene_management/entity/Entity.h"

#include <map>

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

protected:
	EntityID AllocateEntityID();

protected:
	std::map<EntityID, Entity*> _entityMap;

	EntityID	_entityIdSeed = 0;
};

NS_AYY_END
