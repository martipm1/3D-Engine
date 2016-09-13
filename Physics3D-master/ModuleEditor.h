#ifndef __MODULEEDITOR_H__  
#define __MODULEEDITOR_H__  
#include "Module.h" 
#include "Globals.h"

union SDL_Event;

class ModuleEditor : public Module {

	ModuleEditor(Application* app, bool start_enabled);

	~ModuleEditor();

	bool Init();

	update_status PreUpdate(float dt) override;

	update_status Update(float dt) override;

	bool CleanUp() override;

	void HandleInput(SDL_Event* event);

	void Draw();

	bool IsHovered();

 };

#endif // __MODULEEDITOR_H__  
