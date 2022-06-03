#include "MeshProductor.h"
#include "resource/mesh/MeshItem.h"

#include <glad/glad.h>

NS_AYY_BEGIN

MeshItem* MeshProductor::CreateQuad()
{
	/*
	[2]		[3]
	-------
	|\		|
	| \		|
	|	\	|
	|	  \	|
	-------
	[0]		[1]
*/

	float vertices[] = {
		-1.0,-1.0, 0.0,
		 1.0,-1.0, 0.0,
		-1.0, 1.0, 0.0,
		 1.0, 1.0, 0.0,
	};


	unsigned int indices[] = {
		0,1,2,
		1,3,2
	};

	unsigned int VBO = 0;
	unsigned int VAO = 0;
	unsigned int EBO = 0;


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	{
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}
	glBindVertexArray(0);

	MeshItem* item = new MeshItem(VAO, VBO, EBO, EVertexFormat::Pos);
	return item;
}

MeshItem* MeshProductor::CreateCube()
{
	return nullptr;
}

MeshItem* MeshProductor::CreateFromFile(const std::string& path)
{
	return nullptr;
}

NS_AYY_END
