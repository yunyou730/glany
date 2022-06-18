#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include <string>

NS_AYY_BEGIN

class RenderPass
{
public:
	RenderPass(const std::string& programKey);

	std::string GetProgramKey() const { return _programKey; }

	bool IsDepthTestEnable() { return _bEnableDepthTest; }
	bool IsStencilTestEnable() { return _bEnableStencilTest; }

protected:
	std::string _programKey;
	
	bool	_bEnableDepthTest = true;
	bool	_bEnableStencilTest = true;
};

NS_AYY_END

