#include "math_util.h"

NS_AYY_BEGIN

void Dump(const glm::mat4& mat)
{
	constexpr unsigned int dimension = mat.length();

	printf("-------------\n");
	for (int row = 0;row < dimension;row++)
	{
		for (int col = 0;col < dimension;col++)
		{
			printf("%.3f ",mat[row][col]);
		}
		printf("\n");
	}
	printf("-------------\n");
}


NS_AYY_END

