#pragma once

#include "data_type.h"
#include "util_func.h"

#include <glm/glm.hpp>
#include <glm/ext/quaternion_common.hpp>

NS_AYY_BEGIN
void Dump(const glm::mat4& mat);

template<typename VectorType>
void Dump(const VectorType& vec)
{
	constexpr unsigned int len = vec.length();
	printf("-------------\n");
	for (int n = 0; n < len; n++)
	{
		printf("%.3f ", vec[n]);
	}
	printf("\n-------------\n");
}

template<typename T>
bool CheckZero(T num)
{
	return glm::abs(num) <= glm::epsilon<T>();
}

NS_AYY_END


