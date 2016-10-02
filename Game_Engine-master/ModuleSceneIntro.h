#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "RNG.h"

#define BOUNCER_TIME 200

#include <cstdint>

struct PhysBody3D;
class Cube;
struct Mesh_str;
class ModuleMesh;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	uint my_id = 0;
	RNG rand_gen;
	vector<Mesh_str> fbx_test;
};
