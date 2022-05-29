#pragma once

#include "core/data_type.h"
#include <string>

#define SAFE_DEL(p) if(p != nullptr) { delete p; p = nullptr;}

#define NS_AYY_BEGIN namespace ayy {
#define NS_AYY_END }
#define USING_NS_AYY using namespace ayy;

#define CLASS_NAME(ClsName) #ClsName

//NS_AYY_BEGIN
void LogWithLevel(LogLevel logLevel, const std::string & msg);
//NS_AYY_END
