#include "CameraComponent.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

NS_AYY_BEGIN

CameraComponent::CameraComponent(Entity* entity)
	:BaseComponent(entity)
{
	_lookDir = glm::vec3(0,0,-1);
	_projMatrix = glm::mat4(1.0);
}

void CameraComponent::Initialize(ECameraProjType projType, const glm::vec3& lookDir)
{
	_projType = projType;
	_lookDir = lookDir;
}

const glm::mat4& CameraComponent::GetProjectionMatrix()
{
	return _projMatrix;
}

void CameraComponent::CalcProjectionMatrix()
{
	// @miao temp only perspective
	_projMatrix = glm::perspective(_fovy, _aspect, _zNear, _zFar);

}

NS_AYY_END
