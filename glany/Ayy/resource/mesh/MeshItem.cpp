#include "MeshItem.h"
#include "MeshManager.h"
#include <glad/glad.h>

NS_AYY_BEGIN

MeshItem::MeshItem(unsigned int vao,
					unsigned int vbo,
					unsigned int ebo,
					unsigned int vertexCount,
					unsigned int indiceCount,
					EVertexFormat vertexFormat)
	:_vao(vao)
	,_vbo(vbo)
	,_ebo(ebo)
	,_vertexCount(vertexCount)
	,_indiceCount(indiceCount)
	,_format(vertexFormat)
{

}

MeshItem::~MeshItem()
{

}

void MeshItem::Bind()
{
	glBindVertexArray(_vao);
}

void MeshItem::UnBind()
{
	glBindVertexArray(0);
}

void MeshItem::DrawCall()
{
	glDrawElements(GL_TRIANGLES, _indiceCount, GL_UNSIGNED_INT, 0);
}

NS_AYY_END
