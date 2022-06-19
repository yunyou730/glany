#include "runtime/ayy.h"
#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "function/scene_management/Scene.h"

#include "engine/Engine.h"

#include "core/util_func.h"

#include "function/scene_management/component/MeshRenderComponent.h"
#include "function/scene_management/component/MeshFilterComponent.h"
#include "function/scene_management/component/TransformComponent.h"
#include "function/scene_management/component/CameraComponent.h"

#include "function/log/Logger.h"
#include "function/io/FileReader.h"

#include "core/math_util.h"

#include "resource/BuiltinResDict.h"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "resource/texture/RawImage.h"
#include "resource/texture/TextureManager.h"


#include "function/render/material/Material.h"
#include "function/render/material/RenderPass.h"


namespace ayy
{

void MathTest(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));

	Projection * View * Model;


	glm::quat q(glm::vec3(10, 20, 30));

	//glm::slerp()

	glm::qua<float> q2();
}

void TextureTest()
{
	//RawImage img;
	//img.Initialize("textures/container.jpg");

	

	printf("\n");
}

void SpriteTest()
{
	glm::mat4 test = glm::mat4(1.0f);
	ayy::Dump(test);

	test = glm::translate(test, glm::vec3(1,2,3));
	ayy::Dump(test);
	ayy::Dump<glm::vec4>(glm::vec4(1,2,3,4));

	//Texture2D* texture = Engine::Instance()->GetTextureManager()->CreateTexture2D("builtin_assets/textures/container.jpg");
	
	auto scene = Engine::Instance()->GetScene();

	// Camera
	{
		auto entity = scene->CreateEntity();
		entity->AddComponent<CameraComponent>()->Initialize(ECameraProjType::Persp, Engine::Instance()->GetWindow()->GetAspectWH());

		entity->GetComponent<TransformComponent>()->SetPosition(0, 0, 1);
		entity->GetComponent<TransformComponent>()->SetForward(glm::vec3(0, 0, -1));
	}

	// Object 1
	if(false)
	{
		auto entity = scene->CreateEntity();

		TransformComponent* transform = entity->GetComponent<TransformComponent>();
		transform->SetScale(0.333f);
		transform->SetPosition(0, 0.3, 0);

		entity->AddComponent<MeshFilterComponent>()->Initialize(BuiltinMesh::kQuad);
		entity->AddComponent<MeshRenderComponent>()->Initialize(BuiltinMaterial::kNormal);
	}
	
	// Object 2
	{
		auto entity = scene->CreateEntity();

		TransformComponent* transform = entity->GetComponent<TransformComponent>();
		transform->SetScale(0.2f);
		transform->SetPosition(0, -0.2, 0);

		entity->AddComponent<MeshFilterComponent>()->Initialize(BuiltinMesh::kQuadUV);
		entity->AddComponent<MeshRenderComponent>()->Initialize(BuiltinMaterial::kPosUV);


		//ayy::Material* material = new ayy::Material();
		//material->AddPass(new ayy::RenderPass(BuiltinProgram::kPosUV));

	}
}

void ModelTest()
{
	
}

}
