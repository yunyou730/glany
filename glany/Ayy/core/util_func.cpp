#include "util_func.h"
#include <iostream>

void LogWithLevel(LogLevel logLevel, const std::string& msg)
{
	std::string logTag = "[log]";
	switch (logLevel)
	{
	case LogLevel::Info:
		logTag = "[info]";
		break;
	case LogLevel::Warning:
		logTag = "[warn]";
		break;
	case LogLevel::Error:
		logTag = "[error]";
		break;
	}
	std::cout << logTag << msg << std::endl;
}
