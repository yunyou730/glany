#include "MeshRenderComponent.h"
#include "function/render/render_command/MeshRenderCommand.h"

NS_AYY_BEGIN

MeshRenderComponent::MeshRenderComponent(Entity* entity)
	:BaseComponent(entity)
{
	
}

MeshRenderComponent::~MeshRenderComponent()
{
	
}

void MeshRenderComponent::Initialize(const std::string& materialKey)
{
	SetMaterial(materialKey);
}

void MeshRenderComponent::Deinitialize()
{

}

void MeshRenderComponent::SetMaterial(const std::string& materialKey)
{
	_materialKey = materialKey;
}

NS_AYY_END
