#pragma once

#include "core/data_type.h"
#include <string>

namespace ayy
{
	class Logger
	{
	public:

		template<typename... Types>
		static void Info(const std::string& format,Types... args)
		{
			LogWithLevel(LogLevel::Info, format, args...);
		}

		template<typename... Types>
		static void Warning(const std::string& format, Types... args)
		{
			LogWithLevel(LogLevel::Warning, format,args...);
		}

		template<typename... Types>
		static void Error(const std::string& format, Types... args)
		{
			LogWithLevel(LogLevel::Error, format, args...);
		}
	};
}
