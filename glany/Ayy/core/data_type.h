#pragma once

#include <glm/glm.hpp>
//#include "core/util_func.h"

namespace ayy
{
	using Dimension2i = glm::ivec2;
	using Dimension2f = glm::vec2;

	using Color4f = glm::vec4;
	using Color3f = glm::vec3;
}

enum class LogLevel
{
	Info,
	Warning,
	Error,
};


