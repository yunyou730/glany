#include "MeshManager.h"
#include "resource/mesh/MeshItem.h"
#include <glad/glad.h>
#include "MeshProductor.h"

#include "resource/BuiltinResDict.h"

NS_AYY_BEGIN
MeshManager::MeshManager()
{

}

MeshManager::~MeshManager()
{

}

void MeshManager::Initialize()
{
	LoadBuiltin();
}

void MeshManager::Deinitialize()
{

}

void MeshManager::AddCache(const std::string& key, MeshItem* item)
{
	_cache.insert(std::make_pair(key,item));
}

void MeshManager::RemoveCache(const std::string& key)
{

}

MeshItem* MeshManager::GetFromCache(const std::string& key)
{
	auto it = _cache.find(key);
	if (it == _cache.end())
	{
		return nullptr;
	}
	return it->second;
}


void MeshManager::LoadBuiltin()
{
	AddCache(BuiltinMesh::kQuad, MeshProductor::CreateQuad());
	AddCache(BuiltinMesh::kQuadUV, MeshProductor::CreateQuadUV());
}


NS_AYY_END
