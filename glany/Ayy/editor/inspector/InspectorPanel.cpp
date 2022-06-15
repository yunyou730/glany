#include "InspectorPanel.h"
#include "imgui.h"

#include "function/scene_management/Scene.h"
#include "function/event/EventManager.h"
#include "function/event/Event.h"

#include "editor/EditorUtil.h"
#include "editor/EditorEvent.h"

#include "engine/Engine.h"

#include "editor/inspector/TransformInspector.h"
#include "editor/inspector/CameraInspector.h"

NS_AYY_EDITOR_BEGIN

void InspectorPanel::OnStart()
{
	_selectEntityInHierarchyCallback = std::bind(&InspectorPanel::OnEntitySelectedInHierarchy, this, std::placeholders::_1);
	Engine::Instance()->GetEventManager()->Register(typeid(SelectEntityInHierarchy*).name(), &_selectEntityInHierarchyCallback);

	_inspectors.push_back(new TransformInspector());
	_inspectors.push_back(new CameraInspector());
}

void InspectorPanel::OnDestroy()
{
	Engine::Instance()->GetEventManager()->UnRegister(typeid(SelectEntityInHierarchy*).name(), &_selectEntityInHierarchyCallback);

	for (auto it : _inspectors)
	{
		delete it;
	}
	_inspectors.clear();
}

void InspectorPanel::OnGUI()
{
	Scene* scene = Engine::Instance()->GetScene();
	Entity* entity = scene->GetEntity(_selectEntityId);

	ImGui::Begin("Inspector");
	if (entity != nullptr)
	{
		// Entity name & Id
		std::string strEntityId = EditorUtil::GetEntityIdTag(_selectEntityId);
		ImGui::Text(strEntityId.c_str());

		// Delete button
		if (ImGui::CollapsingHeader("Entity part"))
		{
			if (ImGui::Button("Delete Entity"))
			{
				Engine::Instance()->GetEventManager()->DispatchEvent<DeleteEntityEvent>(new ayy::DeleteEntityEvent(_selectEntityId));
			}
		}
		
		
		// component inspectors
		for (auto it : _inspectors)
		{
			if (it->ShouldDisplayDetail())
			{
				it->OnGUI();
			}
		}
	}

	ImGui::End();
}

void InspectorPanel::OnEntitySelectedInHierarchy(Event* evt)
{
	SelectEntityInHierarchy* eventItem = dynamic_cast<SelectEntityInHierarchy*>(evt);
	_selectEntityId = eventItem->_entityId;

	Scene* scene = Engine::Instance()->GetScene();
	Entity* entity = scene->GetEntity(_selectEntityId);
	for (auto it : _inspectors)
	{
		it->SwitchEntity(entity);
	}
}

NS_AYY_EDITOR_END
