#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "function/render/rhi/rhi_data_type.h"
#include <string>


NS_AYY_BEGIN
class MeshItem;
class MeshProductor
{
public:
	static MeshItem* CreateQuad();
	static MeshItem* CreateQuadUV();

	static MeshItem* CreateCube();
	static MeshItem* CreateFromFile(const std::string& path);
};

NS_AYY_END
