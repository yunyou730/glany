#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include <string>

NS_AYY_BEGIN

class BuiltinProgram
{
public:
	static const std::string kTest1;
	static const std::string kPosUV;
};

class BuiltinMaterial
{
public:
	static const std::string kNormal;
	static const std::string kPosUV;
};

class BuiltinMesh
{
public:
	static const std::string kQuad;
	static const std::string kQuadUV;
};


NS_AYY_END
