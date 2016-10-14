#ifndef __MODULE_MESH_H__
#define __MODULE_MESH_H__

#include "Globals.h"
#include "Module.h"
#include <vector>

class aiNode;
class aiScene;
class GameObject;

struct Mesh_str
{
	uint id_vertices;
	uint num_vertices;
	uint* vertices = nullptr;
	
	uint id_indices;
	uint num_indices;
	uint* indices = nullptr;

	uint id_normals = 0;
	uint num_normals = 0;
	float* normals = nullptr;

	uint id_uvs = 0;
	uint num_uvs = 0;
	float* uvs = nullptr;
};

class ModuleMesh : public Module
{
	public:
		ModuleMesh(Application* app, bool start_enabled = true);
		~ModuleMesh();

		bool Init();
		bool CleanUp();

		std::vector<Mesh_str> LoadMesh(const char* path);
		void LoadCurrentNode(const aiScene* scene, aiNode* node, GameObject* parent, const char* path);
		uint LoadTexture(const char* path);
};

#endif __MODULE_MESH_H__

