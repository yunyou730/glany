#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

NS_AYY_BEGIN

class Scene;
class GLWindow;
class GUISystem
{
public:
	GUISystem(Scene* scene);
	~GUISystem();

	void Initialize(GLWindow* window);
	void Deinitialize();


	void FrameBegin();
	void FrameEnd();
	void Render();
	
protected:
	Scene* _scene = nullptr;

};

NS_AYY_END

