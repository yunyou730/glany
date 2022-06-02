#include "runtime/Engine.h"

#include "function/window/GLWindow.h"
#include "function/render/RenderSystem.h"
#include "core/util_func.h"
#include <cassert>

#include "resource/mesh/MeshManager.h"
#include "resource/shader/ShaderManager.h"
#include "resource/texture/TextureManager.h"


NS_AYY_BEGIN

Engine* Engine::s_instance = nullptr;

Engine::Engine()
{
	assert(s_instance == nullptr);
	s_instance = this;
	
	_window = new GLWindow();
	_scene = new Scene();
	_renderSystem = new RenderSystem();
	
	_meshManager = new MeshManager();
	_shaderManager = new ShaderManager();
	_textureManager = new TextureManager();
}
	
Engine::~Engine()
{
	SAFE_DEL(_meshManager);
	SAFE_DEL(_shaderManager);
	SAFE_DEL(_textureManager);


	SAFE_DEL(_renderSystem);
	SAFE_DEL(_window);

	s_instance = nullptr;
}

void Engine::Initialize(const EngineLaunchParam& launchParam,Application* app)
{
	_app = app;
	_window->Initialize(launchParam.windowCreateParam);
	_scene->Initialize();
	_renderSystem->Initialize(launchParam.frameRenderState);

	_meshManager->Initialize();
	_shaderManager->Initialize();
	_textureManager->Initialize();

	_app->OnStart();
}

void Engine::Deinitialize()
{
	_app->OnDestroy();
	_window->Deinitialize();
	_scene->Deinitialize();
	_renderSystem->Deinitialize();

	_meshManager->Deinitialize();
	_shaderManager->Deinitialize();
	_textureManager->Deinitialize();
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
