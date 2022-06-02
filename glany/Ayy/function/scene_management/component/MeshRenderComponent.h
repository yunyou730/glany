#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "function/scene_management/component/BaseComponent.h"

#include <string>

NS_AYY_BEGIN

class MeshRenderComponent : public BaseComponent
{
public:
	static const std::string ClsName() { return CLASS_NAME(ayy::MeshRenderComponent); }

public:
	MeshRenderComponent(Entity* entity);


};

NS_AYY_END
