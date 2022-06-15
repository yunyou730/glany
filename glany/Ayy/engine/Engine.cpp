#include "engine/Engine.h"
#include <cassert>
#include "core/util_func.h"

#include "function/window/GLWindow.h"
#include "function/scene_management/Scene.h"
#include "function/render/RenderSystem.h"
#include "function/imgui/GUISystem.h"
#include "function/event/EventManager.h"
#include "function/scene_management/SceneManageSystem.h"

#include "resource/mesh/MeshManager.h"
#include "resource/shader/ShaderManager.h"
#include "resource/texture/TextureManager.h"

#include "editor/Editor.h"

NS_AYY_BEGIN

Engine* Engine::s_instance = nullptr;

Engine::Engine()
{
	assert(s_instance == nullptr);
	s_instance = this;
	
	_window = new GLWindow();
	_scene = new Scene();
	_renderSystem = new RenderSystem(_scene);
	_guiSystem = new GUISystem(_scene);
	_sceneManageSystem = new SceneManageSystem();
	
	_meshManager = new MeshManager();
	_shaderManager = new ShaderManager();
	_textureManager = new TextureManager();
	_editor = new fancy::Editor();
	_eventManager = new EventManager();
}
	
Engine::~Engine()
{
	SAFE_DEL(_meshManager);
	SAFE_DEL(_shaderManager);
	SAFE_DEL(_textureManager);
	SAFE_DEL(_eventManager);

	SAFE_DEL(_sceneManageSystem);
	SAFE_DEL(_renderSystem);
	SAFE_DEL(_guiSystem);
	SAFE_DEL(_window);

	s_instance = nullptr;
}

void Engine::Initialize(const EngineLaunchParam& launchParam,Application* app)
{
	_app = app;
	_window->Initialize(launchParam.windowCreateParam);
	_scene->Initialize();
	_editor->OnStart();

	
	_guiSystem->Initialize(dynamic_cast<GLWindow*>(_window));
	_renderSystem->Initialize(launchParam.frameRenderState);
	_sceneManageSystem->Initialize();

	_meshManager->Initialize();
	_shaderManager->Initialize();
	_textureManager->Initialize();

	_app->OnStart();
}

void Engine::Deinitialize()
{
	_app->OnDestroy();
	_editor->OnDestroy();
	_guiSystem->Deinitialize();
	_renderSystem->Deinitialize();
	_window->Deinitialize();
	_sceneManageSystem->Deinitialize();
	_scene->Deinitialize();

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
	_eventManager->OnFrameBegin();
	_app->OnUpdate();
	_app->OnLateUpdate();
	_eventManager->OnFrameEnd();
}

void Engine::TickRender()
{
	_renderSystem->FrameBegin();
	_guiSystem->FrameBegin();

	_renderSystem->Render();

	if (_editor != nullptr)
	{
		_editor->OnGUI();
	}
	_guiSystem->Render();

	_renderSystem->FrameEnd();
	_guiSystem->FrameEnd();
}

NS_AYY_END
