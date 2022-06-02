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

NS_AYY_END
