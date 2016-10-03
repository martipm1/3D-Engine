#ifndef __MODULE_MESH_H__
#define __MODULE_MESH_H__

#include "Module.h"

struct Mesh_str
{
	uint id_vertices;
	uint num_vertices;
	uint* vertices = nullptr;
	
	uint id_indices;
	uint num_indices;
	uint* indices = nullptr;
};

class ModuleMesh : public Module
{
	public:
		ModuleMesh(Application* app, bool start_enabled = true);
		~ModuleMesh();

		bool Init();
		bool CleanUp();

		std::vector<Mesh_str> LoadMesh(const char* path);
};

#endif __MODULE_MESH_H__

