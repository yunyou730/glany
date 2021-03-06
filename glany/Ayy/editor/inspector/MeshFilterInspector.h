#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "ComponentInspector.h"

#include <glm/glm.hpp>

NS_AYY_EDITOR_BEGIN

class MeshFilterInspector : public ComponentInspector
{
public:
	virtual void OnGUI() override;
	virtual bool ShouldDisplayDetail() override;
	virtual void SwitchEntity(Entity* entity) override;

protected:
	std::string _meshKey;
};

NS_AYY_EDITOR_END


