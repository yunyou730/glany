#pragma once

#include "function/window/Window.h"
#include "core/util_func.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

NS_AYY_BEGIN

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

	GLFWwindow* GetGlfwWindow() const { return _glfwWindow; }

public:
	virtual void OnWindowSizeChanged(float widht, float height) override;
	
protected:
	GLFWwindow* _glfwWindow = nullptr;
};
	
NS_AYY_END
