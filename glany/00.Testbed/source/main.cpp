#include <cstdio>

#include "ayy.h"
#include "Engine.h"

int main()
{
	ayy::MathTest(3.0,glm::vec2(1.0,3.0));

	//void MathTest(float Translate, glm::vec2 const& Rotate)

	ayy::WindowTest();
	printf("00.Testbed\n");

	auto engine = ayy::Engine();
	engine.Initialize();
	engine.Run();
	engine.Deinitialize();
	
	return 0;
}

