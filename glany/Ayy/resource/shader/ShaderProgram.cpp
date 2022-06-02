#include "ShaderProgram.h"
#include <glad/glad.h>

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

NS_AYY_END
