#include "TextureManager.h"

#include "resource/texture/RawImage.h"
#include "resource/texture/Texture2D.h"

NS_AYY_BEGIN

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

void TextureManager::Initialize()
{
	// builtins
	CreateTexture2D("builtin_assets/textures/p1.jpg");
	CreateTexture2D("builtin_assets/textures/p2.jpg");
	CreateTexture2D("builtin_assets/textures/p3.jpg");
	CreateTexture2D("builtin_assets/textures/p4.jpg");
}

void TextureManager::Deinitialize()
{

}

Texture2D* TextureManager::CreateTexture2D(const std::string& imagePath)
{
	RawImage* raw = nullptr;

	if (!IsRawImageInCache(imagePath))
	{
		raw = new RawImage();
		raw->Initialize(imagePath);
		assert(raw->CheckValid());
		_rawMap.insert(std::make_pair(imagePath, raw));
	}
	else
	{
		raw = _rawMap.find(imagePath)->second;
	}

	if (raw != nullptr && raw->CheckValid())
	{
		Texture2D* texture = new Texture2D(++_textureIdAllocator);
		texture->Initialize(raw);

		_tex2DMap.insert(std::make_pair(texture->GetTextureID(),texture));
		return texture;
	}
	return nullptr;
}

bool TextureManager::IsRawImageInCache(const std::string& imagePath)
{
	auto it = _rawMap.find(imagePath);
	return it != _rawMap.end();
}

Texture2D* TextureManager::GetTexture2D(unsigned int textureId)
{
	auto it = _tex2DMap.find(textureId);
	if (it != _tex2DMap.end())
	{
		return it->second;
	}
	return nullptr;
}

NS_AYY_END

