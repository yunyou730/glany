#include "MeshRenderCommand.h"

#include "resource/mesh/MeshManager.h"
#include "resource/shader/ShaderManager.h"
#include "resource/mesh/MeshItem.h"
#include "resource/shader/ShaderProgram.h"

#include "runtime/Engine.h"
#include <cassert>

#include "function/scene_management/component/TransformComponent.h"
#include "function/scene_management/component/MeshRenderComponent.h"
#include "function/scene_management/component/CameraComponent.h"

NS_AYY_BEGIN

void MeshRenderCommand::Initialize(TransformComponent* transformComp, MeshRenderComponent* meshRender,CameraComponent* cameraComp)
{
	_transform = transformComp;
	_meshRender = meshRender;
	_camera = cameraComp;
}

void MeshRenderCommand::Render()
{
	MeshItem* meshItem = Engine::Instance()->GetMeshManager()->GetFromCache(_meshRender->MeshKey());
	ShaderProgram* shaderProgram = Engine::Instance()->GetShaderManager()->GetShader(_meshRender->ShaderKey());

	shaderProgram->Use();
	shaderProgram->SetUniformMatrix4x4("u_Model", _transform->MVPMatrix());
	meshItem->Bind();
	meshItem->DrawCall();
	meshItem->UnBind();
	shaderProgram->UnUse();
}

NS_AYY_END
