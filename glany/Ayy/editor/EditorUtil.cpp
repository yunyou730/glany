#include "EditorUtil.h"

NS_AYY_EDITOR_BEGIN


std::string EditorUtil::GetEntityIdTag(EntityID entityId)
{
	return "entity[" + std::to_string(entityId) + "]";
}

NS_AYY_EDITOR_END


