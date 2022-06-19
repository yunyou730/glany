#include "MaterialManager.h"
#include "function/render/material/Material.h"
#include "function/render/material/RenderPass.h"

#include "core/util_func.h"

#include "resource/BuiltinResDict.h"

NS_AYY_BEGIN

MaterialManager::MaterialManager()
{

}

MaterialManager::~MaterialManager()
{

}

void MaterialManager::Initialize()
{
	InitBuiltin();
}

void MaterialManager::Deinitialize()
{
	for (auto it : _materials)
	{
		Material* material = it.second;
		SAFE_DEL(material);
	}
	_materials.clear();
}

void MaterialManager::RegisterMaterial(const std::string& key, Material* material)
{
	auto it = _materials.find(key);
	assert(it == _materials.end());

	_materials.insert(std::make_pair(key,material));
}

void MaterialManager::UnRegisterMaterial(const std::string& key)
{
	auto it = _materials.find(key);
	if (it != _materials.end())
	{
		_materials.erase(it);
	}
}

Material* MaterialManager::GetMaterial(const std::string& key)
{
	auto it = _materials.find(key);
	if (it != _materials.end())
	{
		return it->second;
	}
	return nullptr;
}

void MaterialManager::InitBuiltin()
{
	// test1
	{
		Material* material = new Material();
		material->Initialize();
		material->AddPass(new RenderPass(BuiltinProgram::kTest1));
		RegisterMaterial(BuiltinMaterial::kNormal, material);
	}
	

	// pos uv
	{
		Material* material = new Material();
		material->Initialize();

		RenderPass* pass = new RenderPass(BuiltinProgram::kPosUV);
		pass->AddRefTextures(RenderPass::TextureData("u_Texture1", 2));
		pass->AddRefTextures(RenderPass::TextureData("u_Texture2", 3));

		material->AddPass(pass);
		RegisterMaterial(BuiltinMaterial::kPosUV, material);
	}
	
}

NS_AYY_END
