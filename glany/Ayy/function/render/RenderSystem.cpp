#include "RenderSystem.h"
#include "core/util_func.h"
#include "function/render/rhi/gl/GLRhi.h"
#include "function/render/RenderPipeline.h"

#include "function/scene_management/Scene.h"
#include "function/scene_management/component/TransformComponent.h"
#include "function/scene_management/component/MeshRenderComponent.h"

NS_AYY_BEGIN

RenderSystem::RenderSystem(Scene* scene)
	:_scene(scene)
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
	//_scene->QueryEntityByComps<TransformComponent,MeshRenderComponent>();
}

NS_AYY_END

