#include "RawImage.h"
#include <stb_image.h>

NS_AYY_BEGIN

RawImage::RawImage()
{

}

RawImage::~RawImage()
{

}

void RawImage::Initialize(const std::string& imagePath)
{
	stbi_set_flip_vertically_on_load(true);
	_rawData = stbi_load(imagePath.c_str(),&_width,&_height,&_channels,0);
}

void RawImage::Deinitialize()
{
	stbi_image_free(_rawData);
	_rawData = nullptr;
}

NS_AYY_END	

