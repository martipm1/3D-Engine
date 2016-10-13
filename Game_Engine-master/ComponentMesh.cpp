#include "ComponentMesh.h"
#include "ComponentTransform.h"
#include "ModuleMesh.h"
#include "Component.h"
#include "GameObject.h"
//Geometry stuff, shouldn't be here ONLY TESTING!
#include "Glew\include\glew.h"
#include "SDL\include\SDL_opengl.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib, "glu32.lib")    /* link OpenGL Utility lib     */
#pragma comment (lib, "opengl32.lib") /* link Microsoft OpenGL lib   */
#pragma comment (lib, "Glew/libx86/glew32.lib") 
//Geometry stuff, shouldn't be here

#include "MathGeoLib\Math\float4x4.h"

ComponentMesh::ComponentMesh(component_type type, Mesh_str* _mesh, GameObject* _parent) : Component(type, "Mesh", _parent)
{
	mesh = _mesh;
	active = true;
}

ComponentMesh::~ComponentMesh()
{
	mesh = nullptr;
}

void ComponentMesh::Update()
{
	if (active)
	{
		GameObject* tmp = this->parent;
		//ComponentTransform* trans = (ComponentTransform*)parent->FindComponent(c_transform);
		//float4x4 matrix = trans->local_mat;
		//glMultMatrixf(*matrix.v);
		
		//Draw the geometry (mesh) :^D
		glEnableClientState(GL_VERTEX_ARRAY);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->id_indices);
		glVertexPointer(3, GL_FLOAT, 0, NULL);
		glDrawElements(GL_TRIANGLES, mesh->num_indices, GL_UNSIGNED_INT, NULL);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}