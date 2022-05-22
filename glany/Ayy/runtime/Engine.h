#pragma once

#include "platform/Window.h"

namespace ayy
{
	class Renderer;
	class Engine
	{
	public:
		static Engine* Instance() { return s_instance; }

	public:
		Engine();
		~Engine();

		void Initialize(const WindowCreateParam& windowCreateParam);
		void Run();
		void Deinitialize();

	protected:
		static Engine* s_instance;
		
		Window* _window = nullptr;
		Renderer* _renderer = nullptr;

	};

}

