#include "EngineLaunchParam.h"

namespace ayy
{
	EngineLaunchParam EngineLaunchParam::BuildLaunchParam(const Dimension2i& windowSize, const std::string& windowCaption, const Color4f& clearColor)
	{
		EngineLaunchParam param;

		param.windowCreateParam.caption = windowCaption;
		param.windowCreateParam.size = windowSize;
		param.frameRenderState.clearColor = clearColor;

		return param;
	}
}
