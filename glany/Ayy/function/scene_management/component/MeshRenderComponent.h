#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "function/scene_management/component/BaseComponent.h"

#include <string>

NS_AYY_BEGIN

class MeshRenderCommand;
class MeshRenderComponent : public BaseComponent
{
public:
	static const std::string ClsName() { return CLASS_NAME(ayy::MeshRenderComponent); }

public:
 	MeshRenderComponent(Entity* entity);
	~MeshRenderComponent();

	void Initialize(const std::string& meshKey, const std::string& shaderKey);
	void Deinitialize();

	MeshRenderCommand* GetRenderCommand() { return _renderCommand; }
	
protected:
	void SetMesh(const std::string& meshKey);
	void SetShader(const std::string& shaderKey);

protected:
	MeshRenderCommand* _renderCommand = nullptr;

};

NS_AYY_END
