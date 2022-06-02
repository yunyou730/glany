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
	
	ShaderHandle GetHandle() const { return _handle; }

	void AttachShader(unsigned int shader);
	void Link();

protected:
	ShaderHandle _handle = 0;
	const std::string _vsCode;
	const std::string _fsCode;
};

NS_AYY_END
