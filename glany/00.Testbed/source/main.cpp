#include <cstdio>

#include "runtime/ayy.h"
#include "engine/EngineLaunchParam.h"
#include "engine/Engine.h"

#include "Testbed.h"

int main()
{
	auto launchParam = ayy::EngineLaunchParam::BuildLaunchParam(ayy::Dimension2f(800,600), "00.Testbed", ayy::Color4f(0.5, 0.7, 0.3, 1.0));
	auto engine = ayy::Engine();

	Testbed testbed;
	engine.Initialize(launchParam,&testbed);
	engine.Run();
	engine.Deinitialize();


	//ayy::WindowTest();
	
	return 0;
}
