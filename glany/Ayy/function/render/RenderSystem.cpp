#include "RenderSystem.h"
#include "core/util_func.h"
#include "function/render/rhi/gl/GLRhi.h"
#include "function/render/RenderPipeline.h"
#include "function/render/render_command/RenderCommand.h"
#include "function/render/render_command/MeshRenderCommand.h"

#include "function/scene_management/Scene.h"
#include "function/scene_management/component/TransformComponent.h"
#include "function/scene_management/component/MeshRenderComponent.h"
#include "function/scene_management/component/CameraComponent.h"

#include <set>
#include <map>
#include <vector>

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
	ClearRenderCommandList();
}

void RenderSystem::Render()
{
	_pipeline->Render(_rhi, _commandList);
}

void RenderSystem::BuildRenderCommandList()
{
	// collect all cameras
	std::vector<Entity*> cameraEntities = _scene->QueryEntity<TransformComponent,CameraComponent>();
	std::map<unsigned int, std::vector<CameraComponent*>> cameraByLayers;
	for (auto it : cameraEntities)
	{
		Entity* entity = it;
		CameraComponent* camComp = entity->GetComponent<CameraComponent>();


		unsigned int layer = camComp->GetLayer();
		auto it = cameraByLayers.find(layer);
		if (it == cameraByLayers.end())
		{
			std::vector<CameraComponent*> vec;
			vec.push_back(camComp);
			cameraByLayers.insert(std::make_pair(layer, vec));
		}
		else
		{
			it->second.push_back(camComp);
		}
	}

	if (cameraByLayers.size() == 0)
	{
		return;
	}

	// collect all render components
	std::vector<Entity*> entities = _scene->QueryEntity<TransformComponent,MeshRenderComponent>();
	for (auto it : entities)
	{
		Entity* entity = it;
		
		TransformComponent* transform = entity->GetComponent<TransformComponent>();
		unsigned int layer = transform->GetVisiblityLayer();

		auto camIt = cameraByLayers.find(layer);
		if (camIt != cameraByLayers.end())
		{
			for (int camIndex = 0; camIndex < camIt->second.size();camIndex++)
			{
				MeshRenderCommand* renderCommand = new MeshRenderCommand();
				renderCommand->Initialize(entity->GetComponent<TransformComponent>() ,entity->GetComponent<MeshRenderComponent>(), camIt->second[camIndex]);
				_commandList.push_back(renderCommand);
			}
		}
	}
}

void RenderSystem::ClearRenderCommandList()
{
	for (auto it : _commandList)
	{
		SAFE_DEL(it);
	}
	_commandList.clear();
}

NS_AYY_END

