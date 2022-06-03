#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include <string>
#include <map>

#include "function/render/rhi/rhi_data_type.h"

NS_AYY_BEGIN

class ShaderProgram;
class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

	void Initialize();
	void Deinitialize();

	ShaderProgram* GetShader(const std::string& key);

protected:
	void CreateBuiltinShaders();
	ShaderProgram* CreateShader(const std::string& vsPath,const std::string& fsPath);

	bool CheckCompileOK(unsigned int shader);
	bool CheckLinkOK(unsigned int shader);

protected:
	std::map<std::string, ShaderProgram*> _cache;
};

NS_AYY_END
