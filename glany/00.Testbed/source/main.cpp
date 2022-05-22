#include <cstdio>

#include "ayy.h"
#include "Engine.h"

int main()
{
	ayy::TestFunc();
	printf("00.Testbed\n");

	auto engine = ayy::Engine();
	engine.Initialize();
	engine.Run();
	engine.Deinitialize();
	
	return 0;
}

