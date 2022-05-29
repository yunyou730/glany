#pragma once

#include "core/util_func.h"
#include "core/data_type.h"
#include "function/render/rhi/rhi_data_type.h"

NS_AYY_BEGIN

class Rhi
{
public:
	virtual void SetClearColor(const Color3f& clearColor) = 0;

	virtual void ClearBufferWithColor() = 0;
	virtual void ClearBufferWithColorDepth() = 0;
	virtual void ClearBufferWithColorDepthStencil() = 0;

	virtual void SubmitDrawCall(MeshHandle meshHandle) = 0;
};

NS_AYY_END
