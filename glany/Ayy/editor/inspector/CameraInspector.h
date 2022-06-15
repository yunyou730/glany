#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "ComponentInspector.h"
#include "function/scene_management/component/CameraComponent.h"

#include <glm/glm.hpp>

NS_AYY_EDITOR_BEGIN

class CameraInspector : public ComponentInspector
{
public:
	virtual void OnGUI() override;
	virtual bool ShouldDisplayDetail() override;
	virtual void SwitchEntity(Entity* entity) override;

protected:
	ECameraProjType GetProjTypeWithIndex(const int index);

protected:
	//ECameraProjType		_projType;
	int _projTypeSelIndex = 0;

	float _orthoHeightRange;
	float _bottom, _top, _left, _right;

	float _fovy;
	float _zNear, _zFar;

};

NS_AYY_EDITOR_END
