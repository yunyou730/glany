#include "Logger.h"
//#include <cstdio>
//#include <cstdarg>

#include <iostream>

namespace ayy
{
	void Logger::Print(LogLevel level, const char* msg)
	{
		std::cout << msg << std::endl;
	}
}
