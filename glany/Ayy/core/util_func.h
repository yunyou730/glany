#pragma once

#include "core/data_type.h"
#include <string>

#define SAFE_DEL(p) if(p != nullptr) { delete p; p = nullptr;}

#define NS_AYY_BEGIN namespace ayy {
#define NS_AYY_END }
#define USING_NS_AYY using namespace ayy;

#define CLASS_NAME(ClsName) #ClsName

#define NS_EDITOR_BEGIN namespace fancy {
#define NS_EDITOR_END }

#define NS_AYY_EDITOR_BEGIN namespace ayy { namespace fancy {
#define NS_AYY_EDITOR_END }}

template<typename... Types>
void LogWithLevel(LogLevel logLevel,const std::string& format, Types... args)
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
	std::string tag = logTag + format + "\n";
	printf(tag.c_str(), args...);
}

