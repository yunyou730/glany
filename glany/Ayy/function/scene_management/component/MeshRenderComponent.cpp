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

void MeshRenderComponent::Initialize(const std::string& meshKey, const std::string& shaderKey)
{
	SetMesh(meshKey);
	SetShader(shaderKey);
}

void MeshRenderComponent::Deinitialize()
{

}

void MeshRenderComponent::SetMesh(const std::string& meshKey)
{
	_meshKey = meshKey;
}

void MeshRenderComponent::SetShader(const std::string& shaderKey)
{
	_shaderKey = shaderKey;
}

NS_AYY_END
