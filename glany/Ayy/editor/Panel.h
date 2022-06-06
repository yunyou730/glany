#pragma once

#include "core/util_func.h"

NS_AYY_EDITOR_BEGIN

class Panel
{
public:
	Panel() {}
	virtual ~Panel() {}
	
	virtual void OnStart() = 0;
	virtual void OnDestroy() = 0;
	virtual void OnGUI() = 0;
};

NS_AYY_EDITOR_END
