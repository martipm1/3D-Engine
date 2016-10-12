#pragma once

#include "Globals.h"
#include "Module.h"
#include "p2DynArray.h"
#include "p2List.h"

class Menu;
class MenuAbout;
class MenuProject;

class ModuleGuiEditor : public Module
{
public:
	ModuleGuiEditor(Application* app, bool start_enabled = true);
	~ModuleGuiEditor();

	bool Init();
	update_status PreUpdate(float dt);
	update_status Update(float dt);
	bool CleanUp() override;

	MenuAbout* about_menu;
	MenuProject* project_menu;

	void SetProjectMenuFps();

private:
	p2List<Menu*> menus_list;
};