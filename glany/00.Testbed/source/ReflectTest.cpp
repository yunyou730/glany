#include "ReflectTest.h"
#include <cstdarg>

double sum(int count, ...)
{
	va_list ap;

	double sum = 0.f;

	va_start(ap, count);

	for (int i = 0;i < count;i++)
	{
		double arg = va_arg(ap,double);
		sum += arg;
	}

	va_end(ap);
	
	return sum;
}


double Sum2()  // ±ß½çÌõ¼ş
{
	return 0;
}

void MyPrint1(const char* s,...)
{
	va_list ap;
	va_start(ap, s);
	void* args = va_arg(ap, void*);
	printf(s,args);
	va_end(ap);

}

