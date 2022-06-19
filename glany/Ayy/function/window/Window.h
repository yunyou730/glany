#pragma once

#include "core/data_type.h"
#include <string>

namespace ayy
{
	struct WindowCreateParam
	{
		WindowCreateParam()
		{
			size = Dimension2i(800,600);
		}

		WindowCreateParam(int width, int height, const std::string& caption)
		{
			size = Dimension2i(width,height);
			this->caption = caption;
		}

		Dimension2i size;
		std::string caption;
	};

	class Window
	{
	public:
		Window() {}
		virtual ~Window() {}

		virtual bool Initialize(const WindowCreateParam& windowCreateParam) = 0;
		virtual void Deinitialize() = 0 ;
		
		virtual bool ShouldClose() const = 0;

		virtual void FrameBegin() = 0;
		virtual void FrameEnd() = 0;

		ayy::Dimension2i GetSize() const 
		{
			return _size;
		}

		int GetWidth() const { return _size.x; }
		int GetHeight() const { return _size.y; }

		float GetAspectWH() const {
			return float(_size.x) / float(_size.y);
		}
	
		virtual void OnWindowSizeChanged(float widht, float height) = 0;

	protected:
		ayy::Dimension2i _size;

	};
}
