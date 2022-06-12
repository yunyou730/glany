#include "HierarchyPanel.h"
#include "imgui.h"

#include "runtime/Engine.h"
#include "function/scene_management/Scene.h"
#include "function/event/EventManager.h"
#include "function/event/Event.h"
#include "editor/EditorUtil.h"
#include "editor/EditorEvent.h"

NS_AYY_EDITOR_BEGIN

void HierarchyPanel::OnStart()
{

}

void HierarchyPanel::OnDestroy()
{

}

void HierarchyPanel::OnGUI()
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
		std::string entityShowId = EditorUtil::GetEntityIdTag(entityId);
		
		if (ImGui::Selectable(entityShowId.c_str(), _selectEntityId == entityId))
		{
			_selectEntityId = entityId;

			Engine::Instance()->GetEventManager()->DispatchEvent<SelectEntityInHierarchy>(new SelectEntityInHierarchy(entityId));
		}
	}

	ImGui::End();
}

NS_AYY_EDITOR_END
