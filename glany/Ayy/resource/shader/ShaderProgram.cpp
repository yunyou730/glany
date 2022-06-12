#include "ShaderProgram.h"
#include <glad/glad.h>

#include "function/log/Logger.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

NS_AYY_BEGIN

ShaderProgram::ShaderProgram(unsigned int program, const std::string& vsCode, const std::string& fsCode)
	:_handle(program)
	,_vsCode(vsCode)
	,_fsCode(fsCode)
{
	
}

void ShaderProgram::AttachShader(unsigned int shader)
{
	glAttachShader(_handle,shader);
}

void ShaderProgram::Link()
{
	glLinkProgram(_handle);
}

void ShaderProgram::Use()
{
	glUseProgram(_handle);
}

void ShaderProgram::UnUse()
{
	glUseProgram(0);
}

void ShaderProgram::SetUniformMatrix4x4(const std::string& uniform, const glm::mat4& value)
{
	int location = glGetUniformLocation(_handle,uniform.c_str());
	if (location >= 0)
	{
		glUniformMatrix4fv(location, 1,GL_FALSE, glm::value_ptr(value));
	}
	else
	{
		//Logger::Warning("uniform [%s] not found", uniform.c_str());
	}
}

void ShaderProgram::SetUniformFloat(const std::string& uniform, float value)
{

}

NS_AYY_END
