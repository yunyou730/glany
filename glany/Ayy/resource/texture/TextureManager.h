#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include <map>
#include <string>

NS_AYY_BEGIN

class Texture2D;
class RawImage;
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void Initialize();
	void Deinitialize();
	
	Texture2D* CreateTexture2D(const std::string& imagePath);
	Texture2D* GetTexture2D(unsigned int textureId);

	const std::map<std::string, RawImage*>& GetRawCache() { return _rawMap; }
	const std::map<unsigned int, Texture2D*>& GetTex2DCache() { return _tex2DMap; }

protected:
	bool IsRawImageInCache(const std::string& imagePath);

protected:
	unsigned int _textureIdAllocator = 0;
protected:
	std::map<std::string, RawImage*>	_rawMap;
	std::map<unsigned int, Texture2D*>	_tex2DMap;


	unsigned int _textureIdSeed = 0;
};
NS_AYY_END
