#include "FileReader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "function/log/Logger.h"

NS_AYY_BEGIN

const std::string FileReader::ReadText(const std::string& path)
{
	std::string result;
	std::ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		std::stringstream stream;
		file.open(path);
		stream << file.rdbuf();
		file.close();
		result = stream.str();
	}
	catch (std::ifstream::failure e)
	{
		Logger::Error("Open file %s failed", path.c_str());
	}

	return result;
}

NS_AYY_END
