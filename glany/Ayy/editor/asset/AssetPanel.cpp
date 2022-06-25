#include "AssetPanel.h"
#include "imgui.h"

#include "engine/Engine.h"
#include "function/scene_management/Scene.h"
#include "function/event/EventManager.h"
#include "function/event/Event.h"
#include "editor/EditorUtil.h"
#include "editor/EditorEvent.h"


#include "resource/mesh/MeshManager.h"
#include "resource/shader/ShaderManager.h"
#include "resource/texture/TextureManager.h"
#include "function/render/material/MaterialManager.h"


NS_AYY_EDITOR_BEGIN

void AssetPanel::OnStart()
{
	_meshManager = Engine::Instance()->GetMeshManager();
	_textureManager = Engine::Instance()->GetTextureManager();
	_shaderManager = Engine::Instance()->GetShaderManager();
	_materialManager = Engine::Instance()->GetMaterialManager();
}

void AssetPanel::OnDestroy()
{

}

void AssetPanel::OnGUI()
{
	Scene* scene = Engine::Instance()->GetScene();
	ImGui::Begin("Asset");
	
	MeshPart();
	TexturePart();
	ShaderPart();
	MaterialPart();
	
	ImGui::End();
}

void AssetPanel::MeshPart()
{
	if (ImGui::TreeNode("Meshes"))
	{
		const std::map<std::string, MeshItem*>& cache = _meshManager->GetCache();
		for (auto it : cache)
		{
			ImGui::Button(it.first.c_str());
		}

		ImGui::TreePop();
	}
}

void AssetPanel::TexturePart()
{
	if (ImGui::TreeNode("Textures"))
	{
		const std::map<std::string, RawImage*>& rawCache = _textureManager->GetRawCache();
		for (auto it : rawCache)
		{
			ImGui::Button(it.first.c_str());
		}
		ImGui::TreePop();
	}
}

void AssetPanel::ShaderPart()
{
	if (ImGui::TreeNode("Shaders"))
	{
		const std::map<std::string, ShaderProgram*>& shaderCache = _shaderManager->GetCache();
		for (auto it : shaderCache)
		{
			ImGui::Button(it.first.c_str());
		}
		ImGui::TreePop();
	}
}

void AssetPanel::MaterialPart()
{
	if (ImGui::TreeNode("Materials"))
	{
		const auto& materialMap = _materialManager->GetAll();
		for (auto it : materialMap)
		{
			ImGui::Button(it.first.c_str());
		}

		ImGui::TreePop();
	}
}

NS_AYY_EDITOR_END
