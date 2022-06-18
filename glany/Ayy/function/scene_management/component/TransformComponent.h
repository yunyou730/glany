#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "BaseComponent.h"

NS_AYY_BEGIN

class TransformComponent : public BaseComponent
{
public:
	static const std::string ClsName() { return CLASS_NAME(ayy::TransformComponent); }
	
public:
	TransformComponent(Entity* entity);

	void SetPosition(const glm::vec3& pos) { _pos = pos; }
	void SetScale(const glm::vec3& scale) { _scale = scale; }

	void SetRotation(const glm::vec3& rotation);
	void SetForward(const glm::vec3& forward);
	glm::vec3 GetForward();

	void SetPosition(float x, float y, float z) { _pos.x = x; _pos.y = y; _pos.z = z; }
		
	void SetScale(const float scale) { _scale = glm::vec3(scale); }
	void SetScale(const float sx, const float sy, const float sz) { _scale.x = sx; _scale.y = sy; _scale.z = sz; }
	void SetScaleX(const float sx) { _scale.x = sx; }
	void SetScaleY(const float sy) { _scale.y = sy; }
	void SetScaleZ(const float sz) { _scale.z = sz; }
 
	glm::vec3 GetPosition() const { return _pos; }
	glm::vec3 GetScale() const { return _scale; }
	glm::vec3 GetRotation() const { return _rotationEachAxis; }
	
	unsigned int GetVisiblityLayer() const { return _visibilityLayer; }

public:
	const glm::mat4& TranslateMatrix();
	const glm::mat4& RotationMatrix();
	const glm::mat4& ScaleMatrix();
	const glm::mat4& ModelMatrix();
	
protected:
	glm::vec3 _pos;
	glm::vec3 _scale;
	glm::vec3 _rotationEachAxis;	// euler in radians
	
	//bool _bMatrixDirty = true;
	glm::mat4 _translateMatrix;
	glm::mat4 _rotationMatrix;
	glm::mat4 _scaleMatrix;
	glm::mat4 _modelMatrix;

	unsigned int _visibilityLayer = 0;
};


NS_AYY_END
