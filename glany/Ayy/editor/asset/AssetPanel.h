#pragma once

#include "core/data_type.h"
#include "core/util_func.h"
#include "editor/Panel.h"
#include "function/scene_management/entity/Entity.h"
#include <functional>

NS_AYY_BEGIN
class Event;
class MeshManager;
class TextureManager;
class ShaderManager;
class MaterialManager;
NS_AYY_END

NS_AYY_EDITOR_BEGIN

class AssetPanel : public Panel
{
public:
	virtual void OnStart() override;
	virtual void OnDestroy() override;
	virtual void OnGUI() override;

protected:
	void MeshPart();
	void TexturePart();
	void ShaderPart();
	void MaterialPart();

protected:
	MeshManager* _meshManager = nullptr;
	TextureManager* _textureManager = nullptr;
	ShaderManager* _shaderManager = nullptr;
	MaterialManager* _materialManager = nullptr;
};

NS_AYY_EDITOR_END


