#pragma once

#include "core/util_func.h"
#include "function/render/rhi/rhi_data_type.h"
#include <string>
#include <map>
#include "MeshProductor.h"

NS_AYY_BEGIN

enum class EVertexFormat
{
	Pos,
	PosUV,
	PosUVColor,
	PosUVColorNorm,
	PosUVColorNormTangent,
};

struct MeshItem
{
	MeshHandle handle = 0;
	EVertexFormat format = EVertexFormat::PosUV;
};

NS_AYY_END
