#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "editor/Panel.h"
#include "function/scene_management/entity/Entity.h"
#include <functional>

NS_AYY_BEGIN
class Event;
NS_AYY_END

NS_AYY_EDITOR_BEGIN

class HierarchyPanel : public Panel
{
public:
	virtual void OnStart() override;
	virtual void OnDestroy() override;
	virtual void OnGUI() override;

protected:
	EntityID	_selectEntityId = 0;

	std::function<void(Event*)> _selectEntityInHierarchyCallback = nullptr;

};

NS_AYY_EDITOR_END


