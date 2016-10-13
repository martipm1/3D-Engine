#include "Application.h"
#include "ModuleMesh.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Component.h"

#include "Assimp\include\cimport.h"
#include "Assimp\include\scene.h"
#include "Assimp\include\postprocess.h"
#include "Assimp\include\cfileio.h"

#include "Glew\include\glew.h"

#pragma comment (lib, "Assimp/libx86/assimp.lib")
#pragma comment (lib, "Glew/libx86/glew32.lib")

using namespace std;


ModuleMesh::ModuleMesh(Application* app, bool start_enabled) : Module(app, start_enabled)
{}

ModuleMesh::~ModuleMesh()
{}

bool ModuleMesh::Init()
{
	//Use console to LOG debug stuff from assimp
	//struct aiLogStrem stream;
	//stream = aiGetPredefinedLogStream(aiDefaultLogStream_DEBUGGER, nullprt);
	//aiAttachLogStream(&stream);

	return true;
}

bool ModuleMesh::CleanUp()
{
	//Stop debbuging through the console
	//aiDetachAllLogStreams();

	return true;
}

vector<Mesh_str> ModuleMesh::LoadMesh(const char* path)
{
	vector<Mesh_str> full_mesh;

	const aiScene* scene = aiImportFile(path, aiProcessPreset_TargetRealtime_MaxQuality);

	if (scene != nullptr && scene->HasMeshes())
	{
		aiNode* root_node = scene->mRootNode;

		//USE NODES TO ITERATE ALL THE SCENE
		for (int i = 0; i < root_node->mNumChildren; i++)
		{
			LoadCurrentNode(scene, root_node, NULL, path);
		}

		aiReleaseImport(scene);
	}
	else
		LOG("Error loading scene %s", path);

	return full_mesh;
}

void ModuleMesh::LoadCurrentNode(const aiScene* scene, aiNode* node, GameObject* parent, const char* path)
{
	GameObject* g_object = nullptr;

	//Getting the mesh, now it's only one
	for (int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh_to_load = scene->mMeshes[node->mMeshes[i]];
		Mesh_str* mesh = new Mesh_str();
		//VERTICES
		mesh->num_vertices = mesh_to_load->mNumVertices;
		mesh->vertices = new uint[mesh->num_vertices * 3];
		memcpy(mesh->vertices, mesh_to_load->mVertices, sizeof(float)*mesh->num_vertices * 3);
		//INDICES
		if (mesh_to_load->HasFaces())
		{
			mesh->num_indices = mesh_to_load->mNumFaces * 3;
			mesh->indices = new uint[mesh->num_indices];
			for (uint j = 0; j < mesh_to_load->mNumFaces; j++)
			{
				if (mesh_to_load->mFaces[j].mNumIndices != 3)
				{
					LOG("WARNING: geometry with indices != 3 found");
				}
				else
				{
					memcpy(&mesh->indices[j * 3], mesh_to_load->mFaces[j].mIndices, 3 * sizeof(uint));
				}
			}
		}
		//Vertices buffer
		glGenBuffers(1, (GLuint*)&(mesh->id_vertices));
		glBindBuffer(GL_ARRAY_BUFFER, mesh->id_vertices);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * mesh->num_vertices, mesh->vertices, GL_STATIC_DRAW);
		//Indices buffer
		glGenBuffers(1, (GLuint*)&(mesh->id_indices));
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->id_indices);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * mesh->num_indices, mesh->indices, GL_STATIC_DRAW);

		if (mesh_to_load->HasPositions())
		{
			//Getting the transformation
			aiVector3D translation;
			aiVector3D scaling;
			aiQuaternion rotation;

			node->mTransformation.Decompose(scaling, rotation, translation);

			float3 pos(translation.x, translation.y, translation.z);
			float3 scale(scaling.x, scaling.y, scaling.z);
			Quat rot(rotation.x, rotation.y, rotation.z, rotation.w);

			g_object = App->go_manager->CreateGameObject(node->mName.C_Str(), parent);
			g_object->AddComponent(c_transform, pos, scale, rot, g_object);
		}

		//Mesh complete! Send it to GameObject as a Mesh Component
		g_object->AddComponent(c_mesh, mesh, g_object);
	}

	for (int i = 0; i < node->mNumChildren; i++)
	{
		LoadCurrentNode(scene, node->mChildren[i], g_object, path);
	}
}