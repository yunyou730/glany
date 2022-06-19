#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "BaseComponent.h"

#include "glm/glm.hpp"

NS_AYY_BEGIN

enum class ECameraProjType
{
	Ortho,
	Persp,
};

class CameraComponent : public BaseComponent
{
public:
	static const std::string ClsName() { return CLASS_NAME(ayy::CameraComponent); }

public:
	CameraComponent(Entity* entity);

	void Initialize(ECameraProjType projType,float viewportWidth,float viewportHeight);
	const glm::mat4& GetProjectionMatrix();
	const unsigned int GetLayer() const { return _layer; }


public:
	ECameraProjType GetProjType() const { return _projType; }
	void SetProjType(ECameraProjType projType) { _projType = projType; }

	void GetOrthoScope(float& top, float& bottom, float& left, float& right) {
		top = _top; bottom = _bottom; left = _left; right = _right;
	}
	void SetOrthoScope(float orthoHeightRange);

	float GetFovy() const { return _fovy; }
	void SetFovy(float fovy) { _fovy = fovy; }

	void GetNearFar(float& zNear, float& zFar) {
		zNear = _zNear;
		zFar = _zFar;
	}

	void SetNearFar(float zNear,float zFar)
	{
		_zNear = zNear;
		_zFar = zFar;
	}
	
	void SetAspectWH(float viewportWidth, float viewportHeight);

protected:
	void CalcProjectionMatrix();
	void UpdateOrthoScope();

protected:
	ECameraProjType	_projType = ECameraProjType::Persp;
	
	glm::mat4	_projMatrix;
	
	unsigned int _layer = 0;
	
	// perspective
	float	_fovy = 60.0f;
	
	// ortho
	float	_top = 1.0f;
	float	_bottom = -1.0f;
	float	_left = -1.0f;
	float	_right = 1.0f;
	
	// common
	float	_aspectWH = 1.0f;	// width / height
	float	_zNear = 0.01f;
	float	_zFar = 1000.f;
};

NS_AYY_END
