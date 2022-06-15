#include "Scene.h"

#include "function/scene_management/component/TransformComponent.h"
#include "function/scene_management/component/CameraComponent.h"

#include "function/event/Event.h"
#include "function/event/EventManager.h"
#include "engine/Engine.h"

#include <typeinfo>

NS_AYY_BEGIN

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::Initialize()
{
	_windowSizeChangedCallback = std::bind(&Scene::OnWindowSizeChanged, this, std::placeholders::_1);
	Engine::Instance()->GetEventManager()->Register(typeid(WindowSizeChangedEvent*).name(), &_windowSizeChangedCallback);
}

void Scene::Deinitialize()
{
	Engine::Instance()->GetEventManager()->UnRegister(typeid(WindowSizeChangedEvent*).name(), &_windowSizeChangedCallback);

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

Entity* Scene::GetEntity(EntityID entityId)
{
	auto it = _entityMap.find(entityId);
	if (it != _entityMap.end())
	{
		return it->second;
	}
	return nullptr;
}

void Scene::OnWindowSizeChanged(Event* eventItem)
{
	WindowSizeChangedEvent* sizeChangedEvt = dynamic_cast<WindowSizeChangedEvent*>(eventItem);

	std::vector<Entity*> entities = QueryEntity<CameraComponent>();
	for (auto it = entities.begin();it != entities.end();it++)
	{
		Entity* entity = *it;
		CameraComponent* camera = entity->GetComponent<CameraComponent>();
		camera->SetAspectWH(Engine::Instance()->GetWindow()->GetAspectWH());
	}
}

NS_AYY_END
