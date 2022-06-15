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

void CameraComponent::Initialize(ECameraProjType projType, const glm::vec3& lookDir,float aspectWH)
{
	_projType = projType;
	_lookDir = lookDir;
	SetAspectWH(aspectWH);
}

void CameraComponent::SetAspectWH(float aspectWH)
{
	_aspectWH = aspectWH;
	UpdateOrthoScope();
}

void CameraComponent::UpdateOrthoScope()
{
	float width = _aspectWH * (_top - _bottom);
	_left = -width * 0.5f;
	_right = width * 0.5f;
}

void CameraComponent::SetOrthoScope(float orthoHeightRange)
{
	_top = orthoHeightRange * 0.5f;
	_bottom = -_top;
	UpdateOrthoScope();
}

const glm::mat4& CameraComponent::GetProjectionMatrix()
{
	CalcProjectionMatrix();
	return _projMatrix;
}

void CameraComponent::CalcProjectionMatrix()
{
	switch (_projType)
	{
		case ECameraProjType::Persp:
			_projMatrix = glm::perspective(glm::radians(_fovy), _aspectWH, _zNear, _zFar);
			break;
		case ECameraProjType::Ortho:
			_projMatrix = glm::ortho(_left, _right, _bottom, _top);
			break;
		default:
			break;
	}
}

NS_AYY_END
