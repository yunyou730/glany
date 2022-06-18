#include "TransformComponent.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

#include <glm/gtc/quaternion.hpp>

NS_AYY_BEGIN

static const glm::vec3 kDefaultForward(0, 0, 1);

TransformComponent::TransformComponent(Entity* entity)
	:BaseComponent(entity)
{
	_pos = glm::vec3(0, 0, 0);
	_scale = glm::vec3(1, 1, 1);

	// all about rotation
	_rotationEachAxis = glm::vec3(0, 0, 0);
	//_forward = glm::vec3(0,0,1);
	//_left = glm::vec3(0,0,1);
	//_up = glm::vec3(0, 1, 0);

	_translateMatrix = glm::mat4(1.0);
	_rotationMatrix = glm::mat4(1.0);
	_scaleMatrix = glm::mat4(1.0);
	_modelMatrix = glm::mat4(1.0);
}

const glm::mat4& TransformComponent::TranslateMatrix() 
{
	_translateMatrix = glm::translate(glm::mat4(1.0), _pos);
	return _translateMatrix;
}

const glm::mat4& TransformComponent::RotationMatrix()
{
	_rotationMatrix = glm::mat4(1.0);
	_rotationMatrix = glm::rotate(_rotationMatrix, _rotationEachAxis.x, glm::vec3(1.0f, 0.0f, 0.0f));
	_rotationMatrix = glm::rotate(_rotationMatrix, _rotationEachAxis.y, glm::vec3(0.0f, 1.0f, 0.0f));
	_rotationMatrix = glm::rotate(_rotationMatrix, _rotationEachAxis.z, glm::vec3(0.0f, 0.0f, 1.0f));
	return _rotationMatrix;
}

//void TransformComponent::LookAt(const glm::vec3& target, const glm::vec3& worldUp)
//{
//	if (target == _pos)
//	{
//		return;
//	}
//
//	_lookDir = glm::normalize((target - _pos));
//	//_rightDir = glm::cross(_lookDir, worldUp);
//	//_upDir = glm::cross(_rightDir, _upDir);
//}


//const glm::vec3 TransformComponent::GetLookDir()
//{
//	return glm::normalize(RotationMatrix() * glm::vec4(0,0,1,0));
//}

const glm::mat4& TransformComponent::ScaleMatrix()
{
	_scaleMatrix = glm::scale(glm::mat4(1.0), _scale);
	return _scaleMatrix;
}

const glm::mat4& TransformComponent::ModelMatrix()
{
	_modelMatrix = TranslateMatrix() * RotationMatrix() * ScaleMatrix();
	return _modelMatrix;
}

void TransformComponent::SetRotation(const glm::vec3& rotation)
{
	_rotationEachAxis = rotation;
}

glm::vec3 TransformComponent::GetForward()
{
	glm::quat q(_rotationEachAxis);
	return q * kDefaultForward;
}

void TransformComponent::SetForward(const glm::vec3& forward)
{
	// how to get a quaternion, means  from  (0,0,1) -> forward direction ?
	//glm::quat q = glm::quatLookAt(forward, glm::vec3(0, 1, 0));
	glm::quat q = glm::quatLookAtLH(forward, glm::vec3(0, 1, 0));
	_rotationEachAxis = glm::eulerAngles(q);
}

NS_AYY_END
