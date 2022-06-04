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

	void Initialize(ECameraProjType projType,const glm::vec3& lookDir);

	const glm::mat4& GetViewMatrix();
	const glm::mat4& GetProjectionMatrix();

	const unsigned int GetLayer() const { return _layer; }

protected:
	void CalcViewMatrix();
	void CalcProjectionMatrix();

protected:
	glm::vec3	_lookDir;
	ECameraProjType	_projType = ECameraProjType::Persp;

	glm::mat4	_viewMatrix;
	glm::mat4	_projMatrix;


	unsigned int _layer = 0;
};

NS_AYY_END
