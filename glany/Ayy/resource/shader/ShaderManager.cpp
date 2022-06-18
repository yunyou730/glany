#include "ShaderManager.h"
#include  "resource/shader/ShaderProgram.h"

#include "function/io/FileReader.h"
#include "function/log/Logger.h"

#include "resource/BuiltinResDict.h"

#include <glad/glad.h>
#include <cassert>

NS_AYY_BEGIN

ShaderManager::ShaderManager()
{

}

ShaderManager::~ShaderManager()
{

}

void ShaderManager::Initialize()
{
	CreateBuiltinShaders();
}

void ShaderManager::Deinitialize()
{

}

void ShaderManager::CreateBuiltinShaders()
{
	_cache.insert(std::make_pair(BuiltinProgram::kTest1, CreateShader("./builtin_assets/shaders/test1.vs", "./builtin_assets/shaders/test1.fs")));
}

ShaderProgram* ShaderManager::GetShader(const std::string& key)
{
	auto it = _cache.find(key);
	if (it == _cache.end())
	{
		return nullptr;
	}
	return it->second;
}

ShaderProgram* ShaderManager::CreateShader(const std::string& vsPath, const std::string& fsPath)
{
	// vs
	std::string vsCode = FileReader::ReadText(vsPath);
	const char* szVsCode = vsCode.c_str();
	unsigned int vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, &szVsCode, NULL);
	glCompileShader(vertShader);
	assert(CheckCompileOK(vertShader));

	// fs
	std::string fsCode = FileReader::ReadText(fsPath);
	const char* szFsCode = fsCode.c_str();
	unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader,1,&szFsCode,NULL);
	glCompileShader(fragShader);
	assert(CheckCompileOK(fragShader));

	// program
	ShaderProgram* program = new ShaderProgram(glCreateProgram(),vsCode,fsCode);
	program->AttachShader(vertShader);
	program->AttachShader(fragShader);
	program->Link();
	assert(CheckLinkOK(program->GetHandle()));

	return program;
}

bool ShaderManager::CheckCompileOK(unsigned int shader)
{
	int success = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[1024] = { 0 };
		glGetShaderInfoLog(shader,1024,NULL,infoLog);
		Logger::Error("Shader Compile Error:%s",infoLog);
	}
	return success;
}

bool ShaderManager::CheckLinkOK(unsigned int shader)
{
	int success = 0;
	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[1024] = { 0 };
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		Logger::Error("Shader Link Error:%s",infoLog);
	}
	return success;
}

NS_AYY_END
