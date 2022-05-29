#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "function/render/rhi/rhi_data_type.h"
#include <glm/glm.hpp>

NS_AYY_BEGIN

class BaseRenderCommand
{
public:
	VAOHandle		vaoHandle		= 0;
	ShaderHandle	shaderHandle	= 0;
	unsigned int	order			= 0;

	glm::vec3	pos					= glm::vec3(0, 0, 0);
	glm::vec3	rotate				= glm::vec3(0, 0, 0);
	glm::vec3	scale				= glm::vec3(1, 1, 1);
};

class CustomRenderCommand : public BaseRenderCommand
{
public:

};

NS_AYY_END


