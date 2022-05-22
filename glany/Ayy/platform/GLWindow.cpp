#include "GLWindow.h"

#include "runtime/Engine.h"
#include "function/log/Logger.h"


namespace ayy
{

	GLWindow::GLWindow()
	{
	
	}

	GLWindow::~GLWindow() 
	{
	
	}

	bool GLWindow::Initialize(const WindowCreateParam& windowCreateParam)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


		_glfwWindow = glfwCreateWindow(windowCreateParam.size.x, windowCreateParam.size.y, windowCreateParam.caption.c_str(), NULL, NULL);
		if (_glfwWindow == NULL)
		{
			Engine::Instance()->GetLogger()->Print(LogLevel::Error, "Failed to create GLFW window");
			glfwTerminate();

			return false;
		}
		glfwMakeContextCurrent(_glfwWindow);


		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Engine::Instance()->GetLogger()->Print(LogLevel::Error, "Failed to initialize GLAD");
			return false;
		}


		return true;
	}

	void GLWindow::Deinitialize()
	{
		glfwTerminate();
	}
	

	bool GLWindow::ShouldClose() const
	{
		return glfwWindowShouldClose(_glfwWindow);
	}


	void GLWindow::FrameBegin()
	{
	
	}

	void GLWindow::FrameEnd()
	{
		glfwSwapBuffers(_glfwWindow);
		glfwPollEvents();
	}

}