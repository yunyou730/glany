#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include <string>

NS_AYY_BEGIN

class RawImage;
class Texture2D
{
public:
	Texture2D(unsigned int textureId);
	~Texture2D();

	void Initialize(RawImage* rawImage);
	void Deinitialize();
	
	unsigned int GetTextureID() { return _textureId; }
	unsigned int GetGLTextureID() { return _glTextureId; }

protected:
	unsigned int _textureId = 0;
	unsigned int _glTextureId = 0;
};
NS_AYY_END
