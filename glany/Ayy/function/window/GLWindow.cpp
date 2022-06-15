#include "GLWindow.h"
#include "function/log/Logger.h"
#include "function/event/Event.h"
#include "function/event/EventManager.h"
#include "engine/Engine.h"
#include <functional>

NS_AYY_BEGIN

static GLWindow* s_windowInstance = nullptr;

static void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	if (s_windowInstance != nullptr)
	{
		s_windowInstance->OnWindowSizeChanged(width,height);
	}
};

GLWindow::GLWindow()
{
	s_windowInstance = this;
}

GLWindow::~GLWindow()
{
	s_windowInstance = nullptr;
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
		Logger::Error("Failed to create GLFW window");
		glfwTerminate();

		return false;
	}
	glfwMakeContextCurrent(_glfwWindow);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Logger::Error("Failed to create GLFW window");
		return false;
	}
	Logger::Info("GLWindow::Initialize Success");
	
	glfwSetFramebufferSizeCallback(_glfwWindow,frameBufferSizeCallback);

	OnWindowSizeChanged(windowCreateParam.size.x, windowCreateParam.size.y);
	return true;
}

void GLWindow::Deinitialize()
{
	glfwTerminate();
	Logger::Info("GLWindow::Deinitialize");
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

void GLWindow::OnWindowSizeChanged(float width, float height)
{
	glViewport(0, 0, width, height);
	_size = ayy::Dimension2f(width, height);
	
	Engine::Instance()->GetEventManager()->DispatchEvent(new WindowSizeChangedEvent(width,height));
}

NS_AYY_END