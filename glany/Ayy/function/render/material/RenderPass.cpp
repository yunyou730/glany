#include "RenderPass.h"

NS_AYY_BEGIN

RenderPass::RenderPass(const std::string& programKey)
	:_programKey(programKey)
{

}

void RenderPass::AddRefTextures(const TextureData& textureData)
{
	_referenceTextures.push_back(textureData);
}

NS_AYY_END
