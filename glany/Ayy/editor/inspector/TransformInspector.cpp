#include "TransformInspector.h"
#include "imgui.h"

#include "function/scene_management/component/TransformComponent.h"

static const float kMin = -1.0f;
static const float kMax = 1.0f;

NS_AYY_EDITOR_BEGIN

bool TransformInspector::ShouldDisplayDetail()
{
	return GetEntity() != nullptr && GetEntity()->GetComponent<TransformComponent>() != nullptr;
}

void TransformInspector::SwitchEntity(Entity* entity)
{
	ComponentInspector::SwitchEntity(entity);
	if (ShouldDisplayDetail())
	{
		TransformComponent* transform = GetEntity()->GetComponent<TransformComponent>();

		_pos[0] = transform->GetPosition().x;
		_pos[1] = transform->GetPosition().y;
		_pos[2] = transform->GetPosition().z;

		_rot = transform->GetRotation();
		_scale = transform->GetScale();
	}
}

void TransformInspector::OnGUI()
{
	TransformComponent* transform = GetEntity()->GetComponent<TransformComponent>();

	if (ImGui::CollapsingHeader("TransformComponent"))
	{
		ImGui::SliderFloat3("pos", &_pos[0], kMin, kMax);
		transform->SetPosition(_pos[0], _pos[1], _pos[2]);
	}
	//transform->SetPosition()
}


NS_AYY_EDITOR_END
