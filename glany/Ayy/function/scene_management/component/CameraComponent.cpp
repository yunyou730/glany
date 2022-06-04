#include "CameraComponent.h"

NS_AYY_BEGIN

CameraComponent::CameraComponent(Entity* entity)
	:BaseComponent(entity)
{
	_lookDir = glm::vec3(0,0,-1);
	_projMatrix = glm::mat4(1.0);
	_viewMatrix = glm::mat4(1.0);
}

void CameraComponent::Initialize(ECameraProjType projType, const glm::vec3& lookDir)
{
	_projType = projType;
	_lookDir = lookDir;
}

const glm::mat4& CameraComponent::GetViewMatrix()
{
	return _viewMatrix;
}

const glm::mat4& CameraComponent::GetProjectionMatrix()
{
	return _projMatrix;
}

NS_AYY_END
