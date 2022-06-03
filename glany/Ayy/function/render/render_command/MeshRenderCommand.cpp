#include "MeshRenderCommand.h"

#include "resource/mesh/MeshManager.h"
#include "resource/shader/ShaderManager.h"
#include "resource/mesh/MeshItem.h"
#include "resource/shader/ShaderProgram.h"

#include "runtime/Engine.h"
#include <cassert>

NS_AYY_BEGIN

void MeshRenderCommand::Render()
{
	MeshItem* meshItem = Engine::Instance()->GetMeshManager()->GetFromCache(meshHandle);
	ShaderProgram* shaderProgram = Engine::Instance()->GetShaderManager()->GetShader(shaderHandle);

	shaderProgram->Use();
	meshItem->Bind();
	meshItem->DrawCall();
	meshItem->UnBind();
	shaderProgram->UnUse();
}

NS_AYY_END


