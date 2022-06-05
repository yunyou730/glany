#include "Editor.h"
#include "imgui.h"

#include "Hierarchy.h"
#include "Inspector.h"

#include "runtime/Engine.h"
#include "function/scene_management/Scene.h"

NS_AYY_EDITOR_BEGIN

void Editor::OnStart()
{
	_panels.push_back(new Hierarchy());
	_panels.push_back(new Inspector());
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