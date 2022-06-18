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

	void Initialize(const std::string& materialKey);
	void Deinitialize();
	
	std::string GetMaterialKey() const { return _materialKey; }

protected:
	void SetMaterial(const std::string& materialKey);

protected:
	std::string _materialKey;
};

NS_AYY_END
