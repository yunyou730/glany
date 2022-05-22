#include "runtime/Engine.h"

#include "platform/GLWindow.h"

#include "core/util_func.h"

#include <cassert>

namespace ayy
{

	Engine* Engine::s_instance = nullptr;

	Engine::Engine()
	{
		assert(s_instance == nullptr);
		s_instance = this;
	
		_window = new GLWindow();
	}
	
	Engine::~Engine()
	{
		SAFE_DEL(_window);

		s_instance = nullptr;
	}

	void Engine::Initialize(const WindowCreateParam& windowCreateParam)
	{
		_window->Initialize(windowCreateParam);
	}

	void Engine::Run()
	{
		while (!_window->ShouldClose())
		{
			//glClear(GL_COLOR_BUFFER_BIT);


			_window->FrameBegin();

			_window->FrameEnd();
		}
	}

	void Engine::Deinitialize()
	{
		_window->Deinitialize();
	}

}


