#pragma once

#include "runtime/Application.h"
#include "core/data_type.h"

class Testbed : public ayy::Application
{
public:
	Testbed();
	virtual ~Testbed();

	virtual void OnStart() override;
	virtual void OnUpdate() override;
	virtual void OnLateUpdate() override;
	virtual void OnDestroy() override;
};
