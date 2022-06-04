#include "runtime/ayy.h"
#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "function/scene_management/Scene.h"

#include "runtime/Engine.h"

#include "core/util_func.h"

#include "function/scene_management/component/MeshRenderComponent.h"
#include "function/scene_management/component/TransformComponent.h"
#include "function/scene_management/component/CameraComponent.h"

#include "function/log/Logger.h"
#include "function/io/FileReader.h"

#include "core/math_util.h"

namespace ayy
{
void WindowTest()
{
	std::cout << "ayy:TestFunc3" << std::endl;

	//glfwCreateWindow(100, 100, "", nullptr, nullptr);
	std::cout << "ayy:TestFunc5" << std::endl;


	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		//return -1;

		return;
	}
	glfwMakeContextCurrent(window);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	
	glClearColor(0.5f, 0.7f, 0.3f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

void MathTest(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));


	Projection * View * Model;
}

void SpriteTest()
{
	glm::mat4 test = glm::mat4(1.0f);
	ayy::Dump(test);

	test = glm::translate(test, glm::vec3(1,2,3));
	ayy::Dump(test);

	ayy::Dump<glm::vec4>(glm::vec4(1,2,3,4));
	
	auto scene = Engine::Instance()->GetScene();
	auto entity = scene->CreateEntity();

	TransformComponent* transform = entity->GetComponent<TransformComponent>();
	transform->SetScale(0.2);
	transform->SetPosition(0, 0.5, 0);

	entity->AddComponent<MeshRenderComponent>()->Initialize("@quad","@test1");
	
	entity = scene->CreateEntity();
	entity->AddComponent<CameraComponent>()->Initialize(ECameraProjType::Persp, glm::vec3(0,0,-1));
	//entity->GetComponent<TransformComponent>()->
}

void ModelTest()
{
	
}

}

