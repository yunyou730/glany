#include "MeshItem.h"
#include "MeshManager.h"

NS_AYY_BEGIN

MeshItem::MeshItem(unsigned int vao, unsigned int vbo, unsigned int ebo, EVertexFormat vertexFormat)
	:_vao(vao)
	,_vbo(vbo)
	,_ebo(ebo)
	,_format(vertexFormat)
{

}

MeshItem::~MeshItem()
{

}

void MeshItem::Bind()
{

}

void MeshItem::UnBind()
{

}

NS_AYY_END
