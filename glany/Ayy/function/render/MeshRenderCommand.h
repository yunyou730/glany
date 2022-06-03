#pragma once

#include "function/render/RenderCommand.h"

#include "resource/mesh/MeshItem.h"
#include "resource/shader/ShaderProgram.h"

NS_AYY_BEGIN

class MeshRenderCommand : public BaseRenderCommand
{
public:
	std::string		meshHandle;
	std::string		shaderHandle;
	
	glm::vec3	pos					= glm::vec3(0, 0, 0);
	glm::vec3	rotate				= glm::vec3(0, 0, 0);
	glm::vec3	scale				= glm::vec3(1, 1, 1);
};

NS_AYY_END


