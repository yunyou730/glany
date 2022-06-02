#pragma once

#include "core/util_func.h"
#include <string>

NS_AYY_BEGIN

class FileReader
{
public:
	static const std::string ReadText(const std::string& path);

};

NS_AYY_END
