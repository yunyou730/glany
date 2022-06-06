#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "editor/Panel.h"
#include "function/scene_management/entity/Entity.h"

#include <functional>

namespace ayy
{
	class Event;
}

NS_AYY_EDITOR_BEGIN

class Inspector : public Panel
{
public:
	virtual void OnStart() override;
	virtual void OnDestroy() override;
	virtual void OnGUI() override;

protected:
	void OnEntitySelectedInHierarchy(Event* evt);

protected:
	EntityID	_selectEntityId = 0;

	std::function<void(Event*)> _selectEntityInHierarchyCallback = nullptr;
};

NS_AYY_EDITOR_END


