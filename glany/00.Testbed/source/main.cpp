#include <cstdio>

#include "runtime/ayy.h"
#include "runtime/EngineLaunchParam.h"
#include "runtime/Engine.h"


#include "Testbed.h"

#include "ReflectTest.h"

void ReflTest()
{
	
}

int main()
{
	//ReflTest();

	//ClsA a;
	//printf("%d\n",a.a);



	//extern double sum(int count, ...);
	//double d = sum(3,1.0,2.0,3.0,4.0);
	//printf("%.3f\n",d);


	//BMW<int, char,float> bmw;


	//d = Sum2(1.0,2.0,3.0,4.0);
	//printf("%.3f\n", d);



	//extern void MyPrint1(const char* s, ...);

	//MyPrint1("%d %d", 123, 333);

	//MyPrint1("%d %s %.2f\n", 123, "miao",2.557);


	//MyPrint("test:%d,%s", 3,"fds");

	//return 1;

	//ayy::MathTest(3.0,glm::vec2(1.0,3.0));
	//ayy::WindowTest();
	//printf("00.Testbed %s\n",typename(int));
	
	auto launchParam = ayy::EngineLaunchParam::BuildLaunchParam(ayy::Dimension2f(800,600), "00.Testbed", ayy::Color4f(0.5, 0.7, 0.3, 1.0));
	auto engine = ayy::Engine();

	Testbed testbed;
	engine.Initialize(launchParam,&testbed);
	engine.Run();
	engine.Deinitialize();
	
	return 0;
}


