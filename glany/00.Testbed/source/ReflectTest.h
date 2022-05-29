#pragma once
#include <iostream>

#define ReflMember(MemberType,MemberName) \
MemberType MemberName; 



class ClsA
{
public:
	ClsA() :a(10) {}

	ReflMember(int, a)
};


template<typename... A> 
class BMW
{
public: 
	BMW()
	{
		std::cout << "----1" << std::endl;
	}
};


template<>
class BMW<>
{
public:
	BMW()
	{
		std::cout << "--------------------2" << std::endl;
	}

};	// 递归边界


template<typename Head, typename... Tail>
class BMW<Head, Tail...> : public BMW<Tail...>     //
{
public:
	BMW()
	{
		std::cout << "[type] " << typeid(Head).name() 
					<< "\t[hash]" << typeid(Head).hash_code() 
					<< std::endl;

	}
private:
	Head head = 0;
};

// 边界条件
double Sum2();

template<typename T1, typename... T2>
double Sum2(T1 p, T2... arg)
{
	double ret = p + Sum2(arg...);
	return ret;
}


template<typename... TS>
void MyPrint(const char* s, TS... args)
{
	std::string tag = std::string("[debug]") + std::string(s);
	printf(tag.c_str(), args...);
}

