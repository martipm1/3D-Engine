#pragma once

#include "p2List.h"
#include "Globals.h"
#include "Timer.h"
#include "PerfTimer.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModulePhysics3D.h"
#include "ModuleSceneIntro.h"
#include "ModuleRenderer3D.h"
#include "ModuleCamera3D.h"
#include "ModuleGuiEditor.h"
#include "ModuleMesh.h"
#include "GameObjectManager.h"

class Application
{
public:
	ModuleWindow* window;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleSceneIntro* scene_intro;
	ModulePhysics3D* physics3D;
	ModuleRenderer3D* renderer3D;
	ModuleCamera3D* camera;
	ModuleGuiEditor* editor;
	ModuleMesh* meshes;
	GameObjectManager* go_manager;

private:

	Timer	ms_timer;
	Timer	fps_timer;
	Uint32	frames;
	float	dt;
	int		fps_counter;
	int		last_frame_ms;
	int		last_fps;
	int		capped_ms;
	p2List<Module*> list_modules;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

	void RequestBrowser(const char* url);

	int GetLastFrameFps();

private:

	void AddModule(Module* mod);
	void PrepareUpdate();
	void FinishUpdate();
};