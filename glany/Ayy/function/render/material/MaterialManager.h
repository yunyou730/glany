#pragma once

#include "core/util_func.h"

#include <map>
#include <string>

NS_AYY_BEGIN

class Material;
class MaterialManager
{
public:
	MaterialManager();
	~MaterialManager();

	void Initialize();
	void Deinitialize();
	
	void RegisterMaterial(const std::string& key,Material* material);
	void UnRegisterMaterial(const std::string& key);

	Material* GetMaterial(const std::string& key);

protected:
	void InitBuiltin();

protected:
	std::map<std::string, Material*> _materials;
};

NS_AYY_END
