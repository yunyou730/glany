#pragma once

#include "core/data_type.h"
#include "core/util_func.h"

#include "editor/Panel.h"

NS_AYY_EDITOR_BEGIN

class Inspector : public Panel
{
public:
	virtual void OnGUI() override;
};

NS_AYY_EDITOR_END


