#pragma once

#include "core/util_func.h"

NS_AYY_BEGIN

class Application
{
public:
	Application();
	virtual ~Application();

	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnLateUpdate() = 0;
	virtual void OnDestroy() = 0;
};

NS_AYY_END
