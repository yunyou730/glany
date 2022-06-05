#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include <map>
#include <vector>
#include <functional>

#include "function/event/Event.h"

NS_AYY_BEGIN

class SceneManageSystem
{
public:
	SceneManageSystem();
	~SceneManageSystem();

	void Initialize();
	void Deinitialize();

protected:
	void OnEntityCreateEvent(Event* eventItem);
	void OnEntityDeleteEvent(Event* eventItem);

protected:
	std::function<void(Event*)> _entityCreateCallback = nullptr;
	std::function<void(Event*)> _entityDeleteCallback = nullptr;
};

NS_AYY_END
