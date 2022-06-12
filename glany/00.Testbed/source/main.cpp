#include <cstdio>

#include "runtime/ayy.h"
#include "runtime/EngineLaunchParam.h"
#include "runtime/Engine.h"

#include "Testbed.h"

int main()
{
	auto launchParam = ayy::EngineLaunchParam::BuildLaunchParam(ayy::Dimension2f(800,600), "00.Testbed", ayy::Color4f(0.5, 0.7, 0.3, 1.0));
	auto engine = ayy::Engine();

	Testbed testbed;
	engine.Initialize(launchParam,&testbed);
	engine.Run();
	engine.Deinitialize();
	
	return 0;
}
