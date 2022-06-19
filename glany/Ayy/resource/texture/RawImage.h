#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include <string>

NS_AYY_BEGIN
class RawImage
{
public:
	RawImage();
	~RawImage();

	void Initialize(const std::string& imagePath);
	void Deinitialize();

	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
	int GetChannels() const { return _channels; }
	unsigned char* GetRawData() const { return _rawData; }

	bool CheckValid() { return _rawData != nullptr; }

protected:	
	int _width;
	int _height;
	int _channels;
	unsigned char* _rawData = nullptr;

};
NS_AYY_END
