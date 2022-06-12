#include "TransformInspector.h"
#include "imgui.h"

#include "function/scene_management/component/TransformComponent.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

static const float kPosMin = -1.0f;
static const float kPosMax = 1.0f;

static const float kRotMin = 0.0f;
static const float kRotMax = 3.1415;

static const float kScaleMin = -3.0f;
static const float kScaleMax = 3.0f;

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

		_pos = transform->GetPosition();
		_rot = transform->GetRotation();
		_scale = transform->GetScale();
	}
}

void TransformInspector::OnGUI()
{
	TransformComponent* transform = GetEntity()->GetComponent<TransformComponent>();
	if (ImGui::CollapsingHeader("TransformComponent"))
	{
		ImGui::SliderFloat3("pos", glm::value_ptr(_pos), kPosMin, kPosMax);
		ImGui::SliderFloat3("rot", glm::value_ptr(_rot), kRotMin, kRotMax);
		ImGui::SliderFloat3("scale",glm::value_ptr(_scale),kScaleMin,kScaleMax);
		
		transform->SetPosition(_pos);
		transform->SetRotation(_rot);
		transform->SetScale(_scale);
	}
}


NS_AYY_EDITOR_END
