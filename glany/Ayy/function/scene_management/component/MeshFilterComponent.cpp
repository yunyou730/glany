#include "MeshFilterComponent.h"

NS_AYY_BEGIN

MeshFilterComponent::MeshFilterComponent(Entity* entity)
	:BaseComponent(entity)
{
	
}

MeshFilterComponent::~MeshFilterComponent()
{
	
}

void MeshFilterComponent::Initialize(const std::string& meshKey)
{
	SetMesh(meshKey);
}

void MeshFilterComponent::Deinitialize()
{

}

void MeshFilterComponent::SetMesh(const std::string& meshKey)
{
	_meshKey = meshKey;
}

NS_AYY_END
