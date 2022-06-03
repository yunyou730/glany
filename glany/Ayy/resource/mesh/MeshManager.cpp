#include "MeshManager.h"
#include "resource/mesh/MeshItem.h"
#include <glad/glad.h>
#include "MeshProductor.h"

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
	return nullptr;
}


void MeshManager::LoadBuiltin()
{
	AddCache("@quad", MeshProductor::CreateQuad());
}


NS_AYY_END
