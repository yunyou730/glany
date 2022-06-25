#include "MeshRenderInspector.h"
#include "imgui.h"

#include "function/scene_management/component/MeshRenderComponent.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

NS_AYY_EDITOR_BEGIN

bool MeshRenderInspector::ShouldDisplayDetail()
{
	return GetEntity() != nullptr && GetEntity()->GetComponent<MeshRenderComponent>() != nullptr;
}

void MeshRenderInspector::SwitchEntity(Entity* entity)
{
	ComponentInspector::SwitchEntity(entity);
	if (ShouldDisplayDetail())
	{
		MeshRenderComponent* meshRender = entity->GetComponent<MeshRenderComponent>();
		_materialKey = meshRender->GetMaterialKey();
	}
}

void MeshRenderInspector::OnGUI()
{
	if (ImGui::CollapsingHeader("MeshRenderInspector"))
	{
		ImGui::Text("[material] %s", _materialKey.c_str());
	}
}


NS_AYY_EDITOR_END
