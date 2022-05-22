#pragma once

namespace ayy
{
	struct WindowCreateParam
	{
		

	};

	class Window
	{
	public:
		Window();

		virtual void Initialize(const WindowCreateParam& windowCreateParam) = 0;
		virtual void Deinnitialize() = 0;
		
		virtual void Create();

	};
}