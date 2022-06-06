#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "function/scene_management/entity/Entity.h"
#include <string>

NS_AYY_EDITOR_BEGIN

class EditorUtil
{
public:
	static std::string GetEntityIdTag(EntityID entityId);
};

NS_AYY_EDITOR_END
