#include "platform/Window.h"

namespace ayy
{
	class Renderer;
	class Logger;

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


	public:
		Logger* GetLogger() { return _logger; }

	protected:
		static Engine* s_instance;


		Logger* _logger = nullptr;
		Window* _window = nullptr;
		Renderer* _renderer = nullptr;

	};

}

