#pragma once

#include "core/data_type.h"
#include "core/util_func.h"


#include "BaseComponent.h"

NS_AYY_BEGIN

class TransformComponent : public BaseComponent
{
public:
	static const std::string ClsName() { return CLASS_NAME(ayy::TransformComponent); }

public:
	TransformComponent(Entity* entity);
};

NS_AYY_END
