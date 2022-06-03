#pragma once

#include "core/data_type.h"
#include "RenderState.h"
#include "function/render/rhi/rhi.h"
#include <vector>

NS_AYY_BEGIN

class RenderPipeline;
class RenderCommand;
class Scene;
class RenderSystem
{
public:
	RenderSystem(Scene* scene);
	~RenderSystem();

	void Initialize(const FrameRenderState& frameRenderState);
	void Deinitialize();

	void FrameBegin();
	void FrameEnd();

	void Render();

protected:
	void BuildRenderCommandList();

protected:
	Rhi*			_rhi		= nullptr;
	RenderPipeline* _pipeline	= nullptr;
	std::vector<RenderCommand*>	_commandList;

	Scene* _scene = nullptr;
};

NS_AYY_END
