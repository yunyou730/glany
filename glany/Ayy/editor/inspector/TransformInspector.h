#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "ComponentInspector.h"

#include <glm/glm.hpp>

NS_AYY_EDITOR_BEGIN

class TransformInspector : public ComponentInspector
{
public:
	virtual void OnGUI() override;
	virtual bool ShouldDisplayDetail() override;
	virtual void SwitchEntity(Entity* entity) override;

protected:
	//glm::vec3	_pos;
	float	_pos[3];
	glm::vec3	_rot;
	glm::vec3	_scale;
};

NS_AYY_EDITOR_END


