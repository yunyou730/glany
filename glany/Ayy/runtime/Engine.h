#pragma once

#include "EngineLaunchParam.h"
#include "Application.h"

#include "function/window/Window.h"
#include "function/scene_management/Scene.h"

namespace ayy
{
	class RenderSystem;
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

	protected:
		void TickLogic();
		void TickRender();
		void CalcDeltaTime();
		
	protected:
		static Engine* s_instance;

		Application* _app			= nullptr;
		Window*		_window			= nullptr;
		Scene*		_scene			= nullptr;

		RenderSystem* _renderSystem = nullptr;
	
		float	_lastFrameTimeStamp = 0.f;
		float	_deltaTime = 0.f;
	};
}
