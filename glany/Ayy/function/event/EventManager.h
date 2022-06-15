#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include <functional>
#include <vector>
#include <map>
#include <typeinfo>
#include <string>

NS_AYY_BEGIN

class Event;
class EventManager
{
public:
	EventManager();
	~EventManager();

	template<typename EventType>
	void DispatchEvent(EventType* eventItem)
	{
		std::string eventType = typeid(eventItem).name();
		auto it = _allEvents.find(eventType);
		if (it == _allEvents.end())
		{
			std::vector<Event*> vec = {eventItem};
			_allEvents.insert(std::make_pair(eventType,vec));
		}
		else
		{
			it->second.push_back(eventItem);
		}
	}

	void DispatchEvent(Event* eventItem);

	void Register(const std::string& eventName, std::function<void(Event*)>* func);
	void UnRegister(const std::string& eventName, std::function<void(Event*)>* func);
	
	void OnFrameBegin();
	void OnFrameEnd();

	//void TestListenerFunc(Event* eventItem);

protected:
	void DoDispatch();
	void ClearEvents();


protected:
	std::map<std::string, std::vector<Event*>>	_allEvents;
	std::map<std::string, std::vector<std::function<void(Event*)>*>> _allListeners;
};

NS_AYY_END
