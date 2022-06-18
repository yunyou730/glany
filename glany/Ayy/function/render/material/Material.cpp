#include "Material.h"
#include "core/util_func.h"

NS_AYY_BEGIN

Material::Material()
{

}

Material::~Material()
{

}

void Material::Initialize()
{

}

void Material::Deinitialize()
{
	for(auto it : _passes)
	{
		SAFE_DEL(it);
	}
}

void Material::AddPass(RenderPass* pass)
{
	_passes.push_back(pass);
}

NS_AYY_END
