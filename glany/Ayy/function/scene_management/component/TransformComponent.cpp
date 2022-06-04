#include "TransformComponent.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

NS_AYY_BEGIN

TransformComponent::TransformComponent(Entity* entity)
	:BaseComponent(entity)
{
	_pos = glm::vec3(0, 0, 0);
	_scale = glm::vec3(1, 1, 1);
	_rotationEachAxis = glm::vec3(0, 0, 0);

	_translateMatrix = glm::mat4(1.0);
	_rotationMatrix = glm::mat4(1.0);
	_scaleMatrix = glm::mat4(1.0);
	_mvpMatrix = glm::mat4(1.0);
}

const glm::mat4& TransformComponent::TranslateMatrix() 
{
	//if (_bMatrixDirty)
	//{
		_translateMatrix = glm::translate(glm::mat4(1.0), _pos);
	//}
	return _translateMatrix;
}

const glm::mat4& TransformComponent::RotationMatrix()
{
	//if (_bMatrixDirty)
	//{
		_rotationMatrix = glm::mat4(1.0);
		_rotationMatrix = glm::rotate(_rotationMatrix, _rotationEachAxis.x, glm::vec3(1.0f, 0.0f, 0.0f));
		_rotationMatrix = glm::rotate(_rotationMatrix, _rotationEachAxis.y, glm::vec3(0.0f, 1.0f, 0.0f));
		_rotationMatrix = glm::rotate(_rotationMatrix, _rotationEachAxis.z, glm::vec3(0.0f, 0.0f, 1.0f));
	//}
	return _rotationMatrix;
}

const glm::mat4& TransformComponent::ScaleMatrix()
{
	//if (_bMatrixDirty)
	//{
		_scaleMatrix = glm::scale(glm::mat4(1.0), _scale);
	//}
	return _scaleMatrix;
}

const glm::mat4& TransformComponent::MVPMatrix()
{
	//if (_bMatrixDirty)
	//{
	//	
	//}
	_mvpMatrix = TranslateMatrix() * RotationMatrix() * ScaleMatrix();
	return _mvpMatrix;

}

NS_AYY_END
