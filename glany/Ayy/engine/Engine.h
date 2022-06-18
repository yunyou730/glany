#pragma once

#include "EngineLaunchParam.h"
#include "runtime/Application.h"

#include "function/window/Window.h"

NS_AYY_BEGIN
// Resources
class MeshManager;
class ShaderManager;
class TextureManager;

// Scene & ECS
class Scene;
class RenderSystem;
class GUISystem;
class SceneManageSystem;

// Function Managers
class EventManager;
class MaterialManager;

namespace fancy {
class Editor;
}

class Engine
{
public:
	static Engine* Instance() { return s_instance; }
	
public:
	Engine();
	~Engine();

	void Initialize(const EngineLaunchParam& launchParam,Application* app);
	void Deinitialize();
	void Run();
		
public:
	Scene* GetScene() { return _scene; }
	Window* GetWindow() { return _window; }

public:
	MeshManager* GetMeshManager() { return _meshManager; }
	ShaderManager* GetShaderManager() { return _shaderManager; }
	TextureManager* GetTextureManager() { return _textureManager; }

	EventManager* GetEventManager() { return _eventManager; }
	MaterialManager* GetMaterialManager() { return _materialManager; }

protected:
	void TickLogic();
	void TickRender();
	void CalcDeltaTime();
		
protected:
	static Engine* s_instance;

	Application*		_app			= nullptr;
	Window*				_window			= nullptr;
	Scene*				_scene			= nullptr;
	fancy::Editor*		_editor			= nullptr;

protected:
	RenderSystem*		_renderSystem		= nullptr;
	GUISystem*			_guiSystem			= nullptr;
	SceneManageSystem*	_sceneManageSystem	= nullptr;

protected:
	EventManager*		_eventManager		= nullptr; 
	MaterialManager*	_materialManager	= nullptr;

protected:
	MeshManager*		_meshManager		= nullptr;
	ShaderManager*		_shaderManager		= nullptr;
	TextureManager*		_textureManager		= nullptr;
	
protected:
	float	_lastFrameTimeStamp = 0.f;
	float	_deltaTime = 0.f;
};
//NS_FANCY_END
NS_AYY_END
