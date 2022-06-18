#pragma once

#include "function/render/render_command/RenderCommand.h"

#include "resource/mesh/MeshItem.h"
#include "resource/shader/ShaderProgram.h"

NS_AYY_BEGIN
class TransformComponent;
class CameraComponent;
class MeshFilterComponent;
class MeshRenderComponent;
class MeshItem;
class RenderPass;
class MeshRenderCommand : public RenderCommand
{
public:
	virtual void Render() override;
	void Initialize(TransformComponent* transformComp, MeshFilterComponent* meshFilter,MeshRenderComponent* meshRender,CameraComponent* cameraComp);

protected:
	void RenderOnePass(MeshItem* meshItem, RenderPass* pass);
	glm::mat4 CalcViewMatrix();

protected:
	TransformComponent* _transform = nullptr;
	MeshFilterComponent* _meshFilter = nullptr;
	MeshRenderComponent* _meshRender = nullptr;
	CameraComponent*	_camera = nullptr;
};

NS_AYY_END


