#pragma once

#include "core/util_func.h"
#include "function/render/rhi/rhi_data_type.h"
#include <string>
#include <map>
#include "MeshProductor.h"
#include "resource/mesh/MeshItem.h"

NS_AYY_BEGIN

class MeshManager
{
public:
	MeshManager();
	~MeshManager();

	void Initialize();
	void Deinitialize();

	void AddCache(const std::string& key, MeshHandle handle);
	void RemoveCache(const std::string& key);

	MeshItem GetFromCache(const std::string& key);

protected:
	std::map<std::string, MeshItem>	_meshMap;
};

NS_AYY_END
