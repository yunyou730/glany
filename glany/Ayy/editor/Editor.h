#pragma once

#include "core/util_func.h"
#include <vector>

NS_AYY_EDITOR_BEGIN

class Panel;
class Editor
{
public:
	Editor() {}
	virtual ~Editor() {}

	virtual void OnStart();
	virtual void OnUpdate();
	virtual void OnLateUpdate();
	virtual void OnDestroy();

	virtual void OnGUI();

protected:
	std::vector<Panel*>	_panels;
};

NS_AYY_EDITOR_END
