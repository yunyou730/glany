#pragma once

#include "core/util_func.h"
#include "function/render/rhi/rhi_data_type.h"
#include <string>
#include <map>

NS_AYY_BEGIN

enum class EVertexFormat
{
	Pos,
	PosUV,
	PosUVColor,
	PosUVColorNorm,
	PosUVColorNormTangent,
};

class MeshItem
{
	friend class MeshManager;

public:
	MeshItem(unsigned int vao,
			unsigned int vbo,
			unsigned int ebo,
			unsigned int vertexCount,
			unsigned int indiceCount,
			EVertexFormat vertexFormat);
	~MeshItem();

	void Bind();
	void UnBind();
	void DrawCall();

	EVertexFormat GetFormat() const { return _format; }

protected:
	EVertexFormat _format = EVertexFormat::PosUV;

	unsigned int _vao = 0;
	unsigned int _vbo = 0;
	unsigned int _ebo = 0;

	unsigned int _vertexCount = 0;
	unsigned int _indiceCount = 0;
};

NS_AYY_END
