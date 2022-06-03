#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "function/render/rhi/rhi_data_type.h"
#include <glm/glm.hpp>


NS_AYY_BEGIN

class BaseRenderCommand
{
public:
	unsigned int	order			= 0;

	virtual void Render() = 0;
};

//class CustomRenderCommand : public BaseRenderCommand
//{
//public:
//
//};

NS_AYY_END


