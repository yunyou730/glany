#include "EventManager.h"
#include "Event.h"

NS_AYY_BEGIN

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

void EventManager::OnFrameBegin()
{
	DoDispatch();
	ClearEvents();
}

void EventManager::OnFrameEnd()
{
	
}

// Register listener func to _allListeners
void EventManager::Register(const std::string& eventName, std::function<void(Event*)>* func)
{
	auto it = _allListeners.find(eventName);
	if (it == _allListeners.end())
	{
		std::vector<std::function<void(Event*)>*> funcVec = {func};
		_allListeners.insert(std::make_pair(eventName, funcVec));
	}
	else
	{
		it->second.push_back(func);
	}
}

// Remove listener func from _allListeners
void EventManager::UnRegister(const std::string& eventName, std::function<void(Event*)>* func)
{
	auto it = _allListeners.find(eventName);
	if (it != _allListeners.end())
	{
		std::vector<std::function<void(Event*)>*>& funcVec = it->second;
		for (auto it = funcVec.begin();it != funcVec.end();)
		{
			if (*it == func)
			{
				it = funcVec.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
}

// Each event, to call each listener func
void EventManager::DoDispatch()
{
	// Each type event
	for (auto it : _allEvents)
	{
		const std::string& eventName = it.first;

		// Each Listener
		auto listenerIt = _allListeners.find(eventName);
		if (listenerIt != _allListeners.end())
		{
			for (auto func : listenerIt->second)
			{
				// Each event
				for (auto eventItem : it.second)
				{
					(*func)(eventItem);
				}
			}
			
		}
	}
}

void EventManager::ClearEvents()
{
	for (auto it : _allEvents)
	{
		for (auto eventIt : it.second)
		{
			SAFE_DEL(eventIt);
		}
		it.second.clear();
	}
	_allEvents.clear();
}

//void EventManager::TestListenerFunc(Event* eventItem)
//{
//
//}

NS_AYY_END
