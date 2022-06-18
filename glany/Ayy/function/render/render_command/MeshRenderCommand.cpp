#include "MeshRenderCommand.h"

#include "resource/mesh/MeshManager.h"
#include "resource/shader/ShaderManager.h"
#include "resource/mesh/MeshItem.h"
#include "resource/shader/ShaderProgram.h"

#include "engine/Engine.h"
#include <cassert>

#include "function/scene_management/entity/Entity.h"
#include "function/scene_management/component/TransformComponent.h"
#include "function/scene_management/component/MeshFilterComponent.h"
#include "function/scene_management/component/MeshRenderComponent.h"
#include "function/scene_management/component/CameraComponent.h"

#include "function/render/material/Material.h"
#include "function/render/material/RenderPass.h"
#include "function/render/material/MaterialManager.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

static const glm::vec3 kUp = glm::vec3(0, 1, 0);

NS_AYY_BEGIN

void MeshRenderCommand::Initialize(TransformComponent* transformComp, MeshFilterComponent* meshFilter, MeshRenderComponent* meshRender, CameraComponent* cameraComp)
{
	_transform = transformComp;
	_meshFilter = meshFilter;
	_meshRender = meshRender;
	_camera = cameraComp;
}

void MeshRenderCommand::Render()
{
	MeshItem* meshItem = Engine::Instance()->GetMeshManager()->GetFromCache(_meshFilter->GetMeshKey());
	Material* material = Engine::Instance()->GetMaterialManager()->GetMaterial(_meshRender->GetMaterialKey());

	std::vector<RenderPass*> passes = material->GetPasses();
	for (auto it : passes)
	{
		RenderPass* pass = it;
		RenderOnePass(meshItem,pass);
	}
}

void MeshRenderCommand::RenderOnePass(MeshItem* meshItem, RenderPass* pass)
{
	ShaderProgram* shaderProgram = Engine::Instance()->GetShaderManager()->GetShader(pass->GetProgramKey());

	shaderProgram->Use();
	shaderProgram->SetUniformMatrix4x4("u_Model", _transform->ModelMatrix());
	shaderProgram->SetUniformMatrix4x4("u_Translation", _transform->TranslateMatrix());
	shaderProgram->SetUniformMatrix4x4("u_Rotation", _transform->RotationMatrix());
	shaderProgram->SetUniformMatrix4x4("u_Scale", _transform->ScaleMatrix());
	shaderProgram->SetUniformMatrix4x4("u_View", CalcViewMatrix());
	shaderProgram->SetUniformMatrix4x4("u_Projection", _camera->GetProjectionMatrix());

	meshItem->Bind();
	meshItem->DrawCall();
	meshItem->UnBind();
	shaderProgram->UnUse();
}

glm::mat4 MeshRenderCommand::CalcViewMatrix()
{
	auto cameraTransform = _camera->GetEntity()->GetComponent<TransformComponent>();

	//glm::vec3 lookCenter = cameraTransform->GetPosition() + glm::normalize(_camera->GetLookDir());
	glm::vec3 lookCenter = cameraTransform->GetPosition() + glm::normalize(cameraTransform->GetForward());
	glm::mat4 viewMatrix = glm::lookAt(cameraTransform->GetPosition(), lookCenter, kUp);
	return viewMatrix;
}

NS_AYY_END
