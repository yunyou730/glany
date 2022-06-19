#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include <string>
#include <vector>

NS_AYY_BEGIN

class RenderPass
{
public:
	class TextureData
	{
	public:
		TextureData(const std::string& uniformName, unsigned int textureId)
			:_uniformName(uniformName)
			,_textureId(textureId)
		{
		
		}

		std::string _uniformName;
		unsigned int _textureId;
	};

public:
	RenderPass(const std::string& programKey);

	std::string GetProgramKey() const { return _programKey; }

	bool IsDepthTestEnable() { return _bEnableDepthTest; }
	bool IsStencilTestEnable() { return _bEnableStencilTest; }

	void AddRefTextures(const TextureData& textureData);
	const std::vector<TextureData>& GetRefTextures() { return _referenceTextures; }

protected:
	std::string _programKey;
	
	bool	_bEnableDepthTest = true;
	bool	_bEnableStencilTest = true;
	
	std::vector<TextureData>	_referenceTextures;	// should not more than 16
};

NS_AYY_END

