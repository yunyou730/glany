#include <cstdio>

#include "runtime/ayy.h"
#include "runtime/Engine.h"

int main()
{
	//ayy::MathTest(3.0,glm::vec2(1.0,3.0));
	//ayy::WindowTest();
	printf("00.Testbed\n");

	auto engine = ayy::Engine();
	engine.Initialize(ayy::WindowCreateParam(800, 600, "00.Testbed"));
	engine.Run();
	engine.Deinitialize();
	
	return 0;
}

