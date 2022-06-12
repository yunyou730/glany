#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "function/scene_management/entity/Entity.h"

NS_AYY_EDITOR_BEGIN

class ComponentInspector
{
public:
	virtual void OnGUI() = 0;
	virtual bool ShouldDisplayDetail() = 0;

	virtual void SwitchEntity(Entity* entity);

protected:
	Entity* GetEntity() { return _entity; }

protected:
	Entity* _entity = nullptr;

};

NS_AYY_EDITOR_END


