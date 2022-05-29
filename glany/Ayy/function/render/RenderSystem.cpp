#include "RenderSystem.h"
#include "core/util_func.h"
#include "function/render/rhi/gl/GLRhi.h"
#include "function/render/RenderPipeline.h"


NS_AYY_BEGIN

RenderSystem::RenderSystem()
{
	
}

RenderSystem::~RenderSystem()
{
	
}

void RenderSystem::Initialize(const FrameRenderState& frameRenderState)
{
	_rhi = new GLRhi();
	_pipeline = new RenderPipeline();
}

void RenderSystem::Deinitialize()
{
	SAFE_DEL(_rhi);
	SAFE_DEL(_pipeline);
}

void RenderSystem::FrameBegin()
{
	_pipeline->FrameBegin(_rhi);
	BuildRenderCommandList();
}

void RenderSystem::FrameEnd()
{
	_pipeline->FrameEnd(_rhi);
}

void RenderSystem::Render()
{
	_pipeline->Render(_rhi, _commandList);
}

void RenderSystem::BuildRenderCommandList()
{
	// @miao @todo

}

NS_AYY_END

