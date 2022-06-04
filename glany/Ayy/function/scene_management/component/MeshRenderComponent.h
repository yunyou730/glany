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

	std::string MeshKey() const { return _meshKey; }
	std::string ShaderKey() const { return _shaderKey; }

protected:
	void SetMesh(const std::string& meshKey);
	void SetShader(const std::string& shaderKey);

protected:
	std::string _meshKey;
	std::string _shaderKey;

};

NS_AYY_END
