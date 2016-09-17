#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"

class ModuleEditor : public Module
{
public:
	ModuleEditor(Application* app, bool start_enabled = true);
	~ModuleEditor();

	bool Init();
	update_status Update(float dt);
	update_status PreUpdate(float dt);
	bool CleanUp();

};
