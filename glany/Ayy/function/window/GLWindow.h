#pragma once

#include "function/window/Window.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace ayy
{
	class GLWindow : public Window
	{
	public:
		GLWindow();
		virtual ~GLWindow();

		virtual bool Initialize(const WindowCreateParam& windowCreateParam) override;
		virtual void Deinitialize() override;
		
		virtual bool ShouldClose() const override;

		virtual void FrameBegin() override;
		virtual void FrameEnd() override;

	protected:
		GLFWwindow* _glfwWindow = nullptr;
	};
	
}
