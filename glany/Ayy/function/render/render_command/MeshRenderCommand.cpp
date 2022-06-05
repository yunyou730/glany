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

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi


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
	shaderProgram->SetUniformMatrix4x4("u_View", CalcViewMatrix());

	meshItem->Bind();
	meshItem->DrawCall();
	meshItem->UnBind();
	shaderProgram->UnUse();
}

glm::mat4 MeshRenderCommand::CalcViewMatrix()
{
	glm::vec3 lookCenter = _transform->GetPosition() + glm::normalize(_camera->GetLookDir());
	glm::mat4 viewMatrix = glm::lookAt(_transform->GetPosition(), lookCenter, glm::vec3(0, 1, 0));	
	return viewMatrix;
}

NS_AYY_END
