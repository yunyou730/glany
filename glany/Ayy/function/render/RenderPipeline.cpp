#include "RenderPipeline.h"
#include "function/render/rhi/rhi.h"
#include "function/render/render_command/RenderCommand.h"
#include <vector>

NS_AYY_BEGIN

void RenderPipeline::Initialize()
{

}

void RenderPipeline::Deinitialize()
{

}

void RenderPipeline::FrameBegin(Rhi* rhi)
{
	rhi->SetClearColor(ayy::Color3f(0.3, 0.2, 0.8));
	rhi->ClearBufferWithColor();
}

void RenderPipeline::FrameEnd(Rhi* rhi)
{
	
}

void RenderPipeline::Render(Rhi* rhi,const std::vector<RenderCommand*>& renderCommandList)
{
	for (auto it : renderCommandList)
	{
		RenderCommand* renderCmd = it;
		renderCmd->Render();
	}
}

NS_AYY_END
