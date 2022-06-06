#include "Inspector.h"
#include "imgui.h"

#include "function/scene_management/Scene.h"
#include "function/event/EventManager.h"
#include "function/event/Event.h"

#include "editor/EditorUtil.h"
#include "editor/EditorEvent.h"

#include "runtime/Engine.h"

NS_AYY_EDITOR_BEGIN

void Inspector::OnStart()
{
	_selectEntityInHierarchyCallback = std::bind(&Inspector::OnEntitySelectedInHierarchy, this, std::placeholders::_1);
	Engine::Instance()->GetEventManager()->Register(typeid(SelectEntityInHierarchy*).name(), &_selectEntityInHierarchyCallback);
}

void Inspector::OnDestroy()
{
	Engine::Instance()->GetEventManager()->UnRegister(typeid(SelectEntityInHierarchy*).name(), &_selectEntityInHierarchyCallback);
}

void Inspector::OnGUI()
{
	Scene* scene = Engine::Instance()->GetScene();
	Entity* entity = scene->GetEntity(_selectEntityId);

	ImGui::Begin("Inspector");
	if (entity != nullptr)
	{
		std::string strEntityId = EditorUtil::GetEntityIdTag(_selectEntityId);
		ImGui::Text(strEntityId.c_str());

		if (ImGui::Button("Delete Entity"))
		{
			Engine::Instance()->GetEventManager()->DispatchEvent<DeleteEntityEvent>(new ayy::DeleteEntityEvent(_selectEntityId));
		}

		// Show component properties
		// @miao @todo

	}
	ImGui::End();
}

void Inspector::OnEntitySelectedInHierarchy(Event* evt)
{
	SelectEntityInHierarchy* eventItem = dynamic_cast<SelectEntityInHierarchy*>(evt);
	_selectEntityId = eventItem->_entityId;
}

NS_AYY_EDITOR_END
