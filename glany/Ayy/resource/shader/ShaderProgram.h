#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include <string>
#include <map>

#include "function/render/rhi/rhi_data_type.h"

NS_AYY_BEGIN

class ShaderProgram
{
public:
	ShaderProgram(unsigned int program,const std::string& vsCode,const std::string& fsCode);

	void Use();
	void UnUse();
		
	ShaderHandle GetHandle() const { return _handle; }
	void AttachShader(unsigned int shader);
	void Link();

	void SetUniformMatrix4x4(const std::string& uniform,const glm::mat4& value);
	void SetUniformFloat(const std::string& uniform,float value);

protected:
	ShaderHandle _handle = 0;
	const std::string _vsCode;
	const std::string _fsCode;
};

NS_AYY_END
