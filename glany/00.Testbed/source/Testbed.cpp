#include "Testbed.h"

#include "runtime/Engine.h"
#include "function/scene_management/Scene.h"

Testbed::Testbed()
{
	LogWithLevel(LogLevel::Info, "Testbed::Testbed()");
}

Testbed::~Testbed()
{
	LogWithLevel(LogLevel::Info, "Testbed::~Testbed()");
}

void Testbed::OnStart()
{
	LogWithLevel(LogLevel::Info, "Testbed::OnStart()");


	auto scene = ayy::Engine::Instance()->GetScene();
	scene->CreateEntity();
	scene->CreateEntity();
}

void Testbed::OnUpdate()
{
	//LogWithLevel(LogLevel::Info, "Testbed::OnUpdate()");
}

void Testbed::OnLateUpdate()
{
	//LogWithLevel(LogLevel::Info, "Testbed::OnLateUpdate()");
}

void Testbed::OnDestroy()
{
	LogWithLevel(LogLevel::Info, "Testbed::OnDestroy()");
}
