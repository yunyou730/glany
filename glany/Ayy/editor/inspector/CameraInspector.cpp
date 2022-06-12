#include "CameraInspector.h"
#include "imgui.h"

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

		//camera->GetProjectionMatrix();
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
