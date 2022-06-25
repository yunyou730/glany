#include "MeshFilterInspector.h"
#include "imgui.h"

#include "function/scene_management/component/MeshFilterComponent.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

NS_AYY_EDITOR_BEGIN

bool MeshFilterInspector::ShouldDisplayDetail()
{
	return GetEntity() != nullptr && GetEntity()->GetComponent<MeshFilterComponent>() != nullptr;
}

void MeshFilterInspector::SwitchEntity(Entity* entity)
{
	ComponentInspector::SwitchEntity(entity);
	if (ShouldDisplayDetail())
	{
		MeshFilterComponent* meshFilter = GetEntity()->GetComponent<MeshFilterComponent>();
		_meshKey = meshFilter->GetMeshKey();
	}
}

void MeshFilterInspector::OnGUI()
{
	if (ImGui::CollapsingHeader("MeshFilterInspector"))
	{
		ImGui::Text("[mesh] %s", _meshKey.c_str());
	}
}


NS_AYY_EDITOR_END
