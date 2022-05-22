#include <cstdio>

#include "runtime/ayy.h"
#include "runtime/Engine.h"

int main()
{
	//ayy::MathTest(3.0,glm::vec2(1.0,3.0));
	//ayy::WindowTest();
	printf("00.Testbed\n");

	auto windowCreate = ayy::WindowCreateParam(400,300,"00.Testbed");

	auto engine = ayy::Engine();
	engine.Initialize(windowCreate);
	engine.Run();
	engine.Deinitialize();
	
	return 0;
}

