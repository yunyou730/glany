#include "Editor.h"
#include "imgui.h"

#include "hierarchy/HierarchyPanel.h"
#include "inspector/InspectorPanel.h"
#include "asset/AssetPanel.h"

#include "engine/Engine.h"
#include "function/scene_management/Scene.h"

NS_AYY_EDITOR_BEGIN

void Editor::OnStart()
{
	_panels.push_back(new HierarchyPanel());
	_panels.push_back(new InspectorPanel());
	_panels.push_back(new AssetPanel());

	for (auto it : _panels)
	{
		it->OnStart();
	}
}

void Editor::OnUpdate()
{

}

void Editor::OnLateUpdate()
{

}

void Editor::OnDestroy()
{
	for (auto it : _panels)
	{
		it->OnDestroy();
		delete(it);
	}
	_panels.clear();
}

void Editor::OnGUI()
{
	ImGui::ShowDemoWindow();
	for (auto it : _panels)
	{
		it->OnGUI();
	}

}

NS_AYY_EDITOR_END