#include "SceneManageSystem.h"
#include "function/event/EventManager.h"
#include "function/scene_management/entity/Entity.h"
#include "function/scene_management/Scene.h"
#include "runtime/Engine.h"


NS_AYY_BEGIN
SceneManageSystem::SceneManageSystem()
{

}

SceneManageSystem::~SceneManageSystem()
{

}

void SceneManageSystem::Initialize()
{
	_entityCreateCallback = std::bind(&SceneManageSystem::OnEntityCreateEvent,this,std::placeholders::_1);
	Engine::Instance()->GetEventManager()->Register(typeid(CreateEntityEvent*).name(), &_entityCreateCallback);
	
	_entityDeleteCallback = std::bind(&SceneManageSystem::OnEntityDeleteEvent, this, std::placeholders::_1);
	Engine::Instance()->GetEventManager()->Register(typeid(DeleteEntityEvent*).name(), &_entityDeleteCallback);
}

void SceneManageSystem::Deinitialize()
{
	Engine::Instance()->GetEventManager()->UnRegister(typeid(CreateEntityEvent*).name(), &_entityCreateCallback);
}


void SceneManageSystem::OnEntityCreateEvent(Event* eventItem)
{
	CreateEntityEvent* evt = dynamic_cast<CreateEntityEvent*>(eventItem);
	Engine::Instance()->GetScene()->CreateEntity();
}

void SceneManageSystem::OnEntityDeleteEvent(Event* eventItem)
{
	DeleteEntityEvent* evt = dynamic_cast<DeleteEntityEvent*>(eventItem);
	Engine::Instance()->GetScene()->DestroyEntity(evt->_entityId);
}

NS_AYY_END
