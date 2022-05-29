#pragma once

#include "core/data_type.h"

namespace ayy
{
	enum class ClearType
	{
		Color,
		ColorDepth,
		ColorDepthStencil,
	};

	struct FrameRenderState
	{
		Color4f clearColor = Color4f(1,1,1,1);
		ClearType clearType = ClearType::Color;

		FrameRenderState() {}

		FrameRenderState(const Color4f& clearColor,ClearType clearType)
		{
			this->clearColor = clearColor;
			this->clearType = clearType;
		}

		FrameRenderState(const FrameRenderState& other)
		{
			this->clearColor = other.clearColor;
			this->clearType = other.clearType;
		}

		void operator = (const FrameRenderState& other)
		{
			this->clearColor = other.clearColor;
			this->clearType = other.clearType;
		}
	};
}
