#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include <string>

NS_AYY_BEGIN

class Entity;
class BaseComponent
{
public:
	BaseComponent(Entity* entity);
	virtual ~BaseComponent();
	
	Entity* GetEntity() { return _entity; }

protected:
	Entity* _entity = nullptr;
};



class Test1Component : public BaseComponent
{
public:
	static const std::string ClsName() { return CLASS_NAME(ayy::Test1Component); }
	Test1Component(Entity* entity) :BaseComponent(entity) {}
};

class Test2Component : public BaseComponent
{
public:
	static const std::string ClsName() { return CLASS_NAME(ayy::Test2Component); }
	Test2Component(Entity* entity) :BaseComponent(entity) {}
};


NS_AYY_END
