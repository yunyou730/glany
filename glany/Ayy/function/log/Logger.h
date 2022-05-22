#pragma once

namespace ayy
{
	enum class LogLevel
	{
		Info,
		Warning,
		Error,
	};

	class Logger
	{
	public:
		void Print(LogLevel level,const char* msg);
	};
}
