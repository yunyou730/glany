#include "Hierarchy.h"
#include "imgui.h"

#include "runtime/Engine.h"
#include "function/scene_management/Scene.h"
#include "function/scene_management/entity/Entity.h"
#include "function/event/EventManager.h"
#include "function/event/Event.h"

NS_AYY_EDITOR_BEGIN

void Hierarchy::OnGUI()
{
	Scene* scene = Engine::Instance()->GetScene();
	ImGui::Begin("Hierarchy");


	if (ImGui::Button("Create Entity"))
	{
		Engine::Instance()->GetEventManager()->DispatchEvent<CreateEntityEvent>(new ayy::CreateEntityEvent());
	}


	std::map<EntityID, Entity*>& entityMap = scene->GetEntityMap();
	for (auto it : entityMap)
	{
		EntityID entityId = it.second->GetID();
		std::string entityShowId = "entity[" + std::to_string(entityId) + "]";
		if (ImGui::Button(entityShowId.c_str()))
		{
			Engine::Instance()->GetEventManager()->DispatchEvent<DeleteEntityEvent>(new ayy::DeleteEntityEvent(entityId));
		}
	}

	ImGui::End();
}

NS_AYY_EDITOR_END
