#include "RenderSystem.h"
#include "core/util_func.h"
#include "function/render/rhi/gl/GLRhi.h"
#include "function/render/RenderPipeline.h"
#include "function/render/render_command/RenderCommand.h"
#include "function/render/render_command/MeshRenderCommand.h"

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
	_commandList.clear();
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
	std::vector<Entity*> entities = _scene->QueryEntity<TransformComponent,MeshRenderComponent>();
	for (auto it : entities)
	{
		Entity* entity = it;
		RenderCommand* renderCmd = entity->GetComponent<MeshRenderComponent>()->GetRenderCommand();
		_commandList.push_back(renderCmd);
	}	
}

NS_AYY_END

