#pragma once

#include <string>
#include "core/data_type.h"

#include "function/window/Window.h"
#include "function/render/RenderState.h"


namespace ayy
{
	struct EngineLaunchParam
	{
		static EngineLaunchParam BuildLaunchParam(const Dimension2i& windowSize,const std::string& windowCaption,const Color4f& clearColor);

		WindowCreateParam windowCreateParam;
		FrameRenderState frameRenderState;
	};
}
