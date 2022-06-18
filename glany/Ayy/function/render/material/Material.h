#pragma once

#include "core/util_func.h"
#include "function/render/material/RenderPass.h"

#include <vector>

NS_AYY_BEGIN

class Material
{
public:
	Material();
	~Material();

	void Initialize();
	void Deinitialize();

	void AddPass(RenderPass* pass);

	const std::vector<RenderPass*>& GetPasses() const { return _passes; }

protected:
	std::vector<RenderPass*>	_passes;
};

NS_AYY_END
