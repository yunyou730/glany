#include "Texture2D.h"
#include <stb_image.h>

#include <glad/glad.h>
#include "resource/texture/RawImage.h"

NS_AYY_BEGIN

Texture2D::Texture2D(unsigned int textureId)
	:_textureId(textureId)
{
	glGenTextures(1, &_glTextureId);
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_glTextureId);
}

void Texture2D::Initialize(RawImage* rawImage)
{
	glBindTexture(GL_TEXTURE_2D,_glTextureId);
	{
		// wrap mode
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// fill data
		unsigned int format = rawImage->GetChannels() == 3 ? GL_RGB : GL_RGBA;
		glTexImage2D(GL_TEXTURE_2D,
						0, 
						format,
						rawImage->GetWidth(),rawImage->GetHeight(),0,
						format,
						GL_UNSIGNED_BYTE,
						rawImage->GetRawData());

		// mipmap
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Deinitialize()
{
	
}

NS_AYY_END	
