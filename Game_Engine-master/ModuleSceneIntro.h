#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "RNG.h"

#define BOUNCER_TIME 200

struct PhysBody3D;
class Cube;

//Mesh struct, shouldn't be here
struct Mesh
{
	uint id_indices = 0;
	uint num_indices = 0;
	uint* indices = nullptr;

	uint id_vertices = 0;
	uint num_vertices = 0;
	float* vertices = nullptr;
};
//Mesh struct, shouldn't be here

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
};
