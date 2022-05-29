#include "GLRhi.h"
#include <glad/glad.h>

NS_AYY_BEGIN

void GLRhi::SetClearColor(const Color3f& clearColor)
{
	glClearColor(clearColor.r, clearColor.g, clearColor.b, 1.0);
}

void GLRhi::ClearBufferWithColor()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLRhi::ClearBufferWithColorDepth()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLRhi::ClearBufferWithColorDepthStencil()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GLRhi::SubmitDrawCall(MeshHandle meshHandle)
{

}

NS_AYY_END
