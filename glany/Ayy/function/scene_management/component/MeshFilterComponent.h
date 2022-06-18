#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "function/scene_management/component/BaseComponent.h"

#include <string>

NS_AYY_BEGIN

class MeshFilterComponent : public BaseComponent
{
public:
	static const std::string ClsName() { return CLASS_NAME(ayy::MeshFilterComponent); }

public:
	MeshFilterComponent(Entity* entity);
	~MeshFilterComponent();

	void Initialize(const std::string& meshKey);
	void Deinitialize();

	std::string GetMeshKey() const { return _meshKey; }

protected:
	void SetMesh(const std::string& meshKey);

protected:
	std::string _meshKey;
};

NS_AYY_END
