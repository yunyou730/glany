#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "RenderState.h"
#include <vector>

NS_AYY_BEGIN

class Rhi;
class RenderCommand;
class RenderPipeline
{
public:
	void Initialize();
	void Deinitialize();

	void FrameBegin(Rhi* rhi);
	void FrameEnd(Rhi* rhi);
	void Render(Rhi* rhi, const std::vector<RenderCommand*>& renderCommandList);

protected:
	FrameRenderState		_renderState;
};

NS_AYY_END
