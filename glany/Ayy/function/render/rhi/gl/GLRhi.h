#pragma once

#include "function/render/rhi/rhi.h"


NS_AYY_BEGIN

class GLRhi : public Rhi
{
public:
	virtual void SetClearColor(const Color3f& clearColor) override;

	virtual void ClearBufferWithColor() override;
	virtual void ClearBufferWithColorDepth() override;
	virtual void ClearBufferWithColorDepthStencil() override;

	virtual void SubmitDrawCall(MeshHandle meshHandle) override;
};

NS_AYY_END

