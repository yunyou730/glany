#include "util_func.h"
#include <iostream>

void LogWithLevel(LogLevel logLevel, const std::string& msg)
{
	std::cout << msg << std::endl;
}
