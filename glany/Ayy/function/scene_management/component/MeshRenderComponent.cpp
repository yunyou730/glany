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
	_renderCommand = new MeshRenderCommand();
	SetMesh(meshKey);
	SetShader(shaderKey);
}

void MeshRenderComponent::Deinitialize()
{
	SAFE_DEL(_renderCommand);
}

void MeshRenderComponent::SetMesh(const std::string& meshKey)
{
	_renderCommand->meshHandle = meshKey;
}

void MeshRenderComponent::SetShader(const std::string& shaderKey)
{
	_renderCommand->shaderHandle = shaderKey;
}

NS_AYY_END
