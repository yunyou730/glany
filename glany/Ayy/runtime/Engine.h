#pragma once

#include "EngineLaunchParam.h"
#include "Application.h"

#include "function/window/Window.h"
#include "function/scene_management/Scene.h"

namespace ayy
{
	class RenderSystem;
	class MeshManager;
	class ShaderManager;
	class TextureManager;
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

	public:
		MeshManager* GetMeshManager() { return _meshManager; }
		ShaderManager* GetShaderManager() { return _shaderManager; }
		TextureManager* GetTextureManager() { return _textureManager; }

	protected:
		void TickLogic();
		void TickRender();
		void CalcDeltaTime();
		
	protected:
		static Engine* s_instance;

		Application* _app			= nullptr;
		Window*		_window			= nullptr;
		Scene*		_scene			= nullptr;

	protected:
		RenderSystem* _renderSystem = nullptr;

	protected:
		MeshManager* _meshManager = nullptr;
		ShaderManager* _shaderManager = nullptr;
		TextureManager* _textureManager = nullptr;
	
	protected:
		float	_lastFrameTimeStamp = 0.f;
		float	_deltaTime = 0.f;
	};
}
