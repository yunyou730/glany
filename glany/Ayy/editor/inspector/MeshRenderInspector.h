#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "ComponentInspector.h"

#include <glm/glm.hpp>

NS_AYY_EDITOR_BEGIN

class MeshRenderInspector : public ComponentInspector
{
public:
	virtual void OnGUI() override;
	virtual bool ShouldDisplayDetail() override;
	virtual void SwitchEntity(Entity* entity) override;

protected:
	std::string _materialKey;
};

NS_AYY_EDITOR_END


