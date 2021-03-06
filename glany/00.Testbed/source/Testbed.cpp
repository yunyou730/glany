#include "Testbed.h"

#include "engine/Engine.h"
#include "function/scene_management/Scene.h"
#include "function/Log/Logger.h"


#include "runtime/ayy.h"

Testbed::Testbed()
{
	ayy::Logger::Info("Testbed::Testbed()");
}

Testbed::~Testbed()
{
	ayy::Logger::Info("Testbed::~Testbed()");
}

void Testbed::OnStart()
{
	ayy::Logger::Info("Testbed::OnStart()");
	
	ayy::TextureTest();
	ayy::MathTest(2,glm::vec2());
	ayy::SpriteTest();
}

void Testbed::OnUpdate()
{
	//ayy::Logger::Info(LogLevel::Info, "Testbed::OnUpdate()");
}

void Testbed::OnLateUpdate()
{
	//ayy::Logger::Info(LogLevel::Info, "Testbed::OnLateUpdate()");
}

void Testbed::OnDestroy()
{
	ayy::Logger::Info("Testbed::OnDestroy()");
}
