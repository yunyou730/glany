#include "runtime/Engine.h"

#include "function/window/GLWindow.h"
#include "function/render/RenderSystem.h"
#include "core/util_func.h"
#include <cassert>

NS_AYY_BEGIN

Engine* Engine::s_instance = nullptr;

Engine::Engine()
{
	assert(s_instance == nullptr);
	s_instance = this;
	
	_window = new GLWindow();
	_scene = new Scene();
	_renderSystem = new RenderSystem();
}
	
Engine::~Engine()
{
	SAFE_DEL(_renderSystem);
	SAFE_DEL(_window);

	s_instance = nullptr;
}

void Engine::Initialize(const EngineLaunchParam& launchParam,Application* app)
{
	_app = app;
	_window->Initialize(launchParam.windowCreateParam);
	_scene-
	_renderSystem->Initialize(launchParam.frameRenderState);

	_app->OnStart();
}

void Engine::Deinitialize()
{
	_app->OnDestroy();

	_window->Deinitialize();
	_renderSystem->Deinitialize();
}

void Engine::Run()
{
	while (!_window->ShouldClose())
	{
		_window->FrameBegin();
		
		TickLogic();
		CalcDeltaTime();
		TickRender();
		
		_window->FrameEnd();
	}
}

void Engine::CalcDeltaTime()
{

}

void Engine::TickLogic()
{
	_app->OnUpdate();
	_app->OnLateUpdate();
}

void Engine::TickRender()
{
	_renderSystem->FrameBegin();
	_renderSystem->Render();
	_renderSystem->FrameEnd();
}

NS_AYY_END
