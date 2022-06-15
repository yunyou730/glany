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

		// projection type
		_projTypeSelIndex = (int)camera->GetProjType();

		// ortho 
		camera->GetOrthoScope(_top, _bottom, _left, _right);
		_orthoHeightRange = _top - _bottom;

		// fov
		_fovy = camera->GetFovy();

		// near far
		camera->GetNearFar(_zNear, _zFar);
	}
}

void CameraInspector::OnGUI()
{
	CameraComponent* camera = GetEntity()->GetComponent<CameraComponent>();

	if (ImGui::CollapsingHeader("CameraComponent"))
	{
		// project type
		const char* items[] = {"Ortho","Persp" };
		if (ImGui::Combo("combo", &_projTypeSelIndex, items, IM_ARRAYSIZE(items)))
		{
			ECameraProjType projType = GetProjTypeWithIndex(_projTypeSelIndex);
			camera->SetProjType(projType);
		}
		
		// fov
		ImGui::SliderFloat("fovy", &_fovy,0.0f,180.0f);
		camera->SetFovy(_fovy);
		
		// ortho factors
		ImGui::SliderFloat("orthoHeightRange", &_orthoHeightRange, 0.0f, 10.0f);
		camera->SetOrthoScope(_orthoHeightRange);

		// zNear & zFar
		ImGui::SliderFloat("zNear",&_zNear,0.0f,100.0f);
		ImGui::SliderFloat("zFar", &_zFar,0.0f,1000.0f);
		camera->SetNearFar(_zNear,_zFar);
	}
}

ECameraProjType CameraInspector::GetProjTypeWithIndex(const int index)
{
	ECameraProjType result = ECameraProjType::Persp;
	switch (index)
	{
	case 0:
		result = ECameraProjType::Ortho;
		break;
	case 1:
		result = ECameraProjType::Persp;
		break;
	}

	return result;
}


NS_AYY_EDITOR_END
