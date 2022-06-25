#pragma once

#include "core/util_func.h"
#include "function/render/rhi/rhi_data_type.h"
#include <string>
#include <map>

NS_AYY_BEGIN

class MeshItem;
class MeshManager
{
public:
	MeshManager();
	~MeshManager();

	void Initialize();
	void Deinitialize();

	void AddCache(const std::string& key, MeshItem* item);
	void RemoveCache(const std::string& key);

	MeshItem* GetFromCache(const std::string& key);
	const std::map<std::string, MeshItem*>& GetCache() const { return _cache; }

protected:
	void LoadBuiltin();

protected:
	std::map<std::string, MeshItem*>	_cache;
};

NS_AYY_END
