#include "CameraInspector.h"
#include "imgui.h"

#include "function/scene_management/component/CameraComponent.h"

NS_AYY_EDITOR_BEGIN

bool CameraInspector::ShouldDisplayDetail()
{
	return GetEntity() != nullptr && GetEntity()->GetComponent<CameraComponent>() != nullptr;
}

void CameraInspector::SwitchEntity(Entity* entity)
{
	ComponentInspector::SwitchEntity(entity);
	if (ShouldDisplayDetail())
	{
		CameraComponent* camera = GetEntity()->GetComponent<CameraComponent>();

		//_pos[0] = transform->GetPosition().x;
		//_pos[1] = transform->GetPosition().y;
		//_pos[2] = transform->GetPosition().z;

		//_rot = transform->GetRotation();
		//_scale = transform->GetScale();
	}
}

void CameraInspector::OnGUI()
{
	CameraComponent* camera = GetEntity()->GetComponent<CameraComponent>();

	if (ImGui::CollapsingHeader("CameraComponent"))
	{
		ImGui::Text("Camera component");
	}
}

NS_AYY_EDITOR_END
