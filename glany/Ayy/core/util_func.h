#pragma once

#include "runtime/Engine.h"
#include "core/data_type.h"
#include <cstring>

#define SAFE_DEL(p) if(p != nullptr) { delete p; p = nullptr;}

void LogWithLevel(LogLevel logLevel,const std::string& msg);

