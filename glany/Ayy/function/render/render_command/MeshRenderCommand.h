#pragma once

#include "function/render/render_command/RenderCommand.h"

#include "resource/mesh/MeshItem.h"
#include "resource/shader/ShaderProgram.h"

NS_AYY_BEGIN
class TransformComponent;
class CameraComponent;
class MeshRenderComponent;
class MeshRenderCommand : public RenderCommand
{
public:
	virtual void Render() override;
	void Initialize(TransformComponent* transformComp, MeshRenderComponent* meshRender,CameraComponent* cameraComp);

protected:
	TransformComponent* _transform = nullptr;
	MeshRenderComponent* _meshRender = nullptr;
	CameraComponent*	_camera = nullptr;
};

NS_AYY_END


