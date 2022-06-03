#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "function/render/rhi/rhi_data_type.h"
#include <glm/glm.hpp>


NS_AYY_BEGIN

class RenderCommand
{
public:
	virtual void BeforeRender() {}
	virtual void Render() = 0;
	virtual void AfterRender() {}

	unsigned int	order			= 0;
};

NS_AYY_END


