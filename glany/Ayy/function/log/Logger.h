#pragma once

#include "core/data_type.h"
#include <string>

namespace ayy
{
	class Logger
	{
	public:
		static void Info(const std::string& msg);
		static void Warning(const std::string& msg);
		static void Error(const std::string& msg);
	
	//protected:
	//	void Print(LogLevel level, const std::string& msg);

	};
}
