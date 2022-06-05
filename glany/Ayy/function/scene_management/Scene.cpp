#include "Scene.h"

#include "function/scene_management/component/TransformComponent.h"

NS_AYY_BEGIN

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::Initialize()
{

}

void Scene::Deinitialize()
{
	for(auto it : _entityMap)
	{
		Entity* entity = it.second;
		SAFE_DEL(entity);
	}
	_entityMap.clear();
}

void Scene::Tick()
{

}

Entity* Scene::CreateEntity()
{
	Entity* entity = new Entity(AllocateEntityID());
	entity->AddComponent<TransformComponent>();
	_entityMap.insert(std::make_pair(entity->GetID(),entity));
	return entity;
}

EntityID Scene::AllocateEntityID()
{
	_entityIdSeed++;
	return _entityIdSeed;
}

void Scene::DestroyEntity(EntityID entityId)
{
	auto it = _entityMap.find(entityId);
	if (it != _entityMap.end())
	{
		Entity* entity = it->second;
		_entityMap.erase(it);

		SAFE_DEL(entity);
	}
}

NS_AYY_END
