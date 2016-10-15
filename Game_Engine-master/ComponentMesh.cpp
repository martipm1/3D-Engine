#include "ComponentMesh.h"
#include "ComponentTransform.h"
#include "ComponentMaterial.h"
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
	parent = _parent;
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
		ComponentTransform* trans = (ComponentTransform*)parent->FindComponent(c_transform);
		if (trans)
		{
			float4x4 matrix = trans->GetRenderingMatrix().Transposed();
			glPushMatrix();
			glMultMatrixf(*matrix.v);
		}

		ComponentMaterial* material = (ComponentMaterial*)parent->FindComponent(c_material);
		//TODO: Use texture id to paint on the mesh!!!
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glBindBuffer(GL_ARRAY_BUFFER, mesh->id_vertices);
		glVertexPointer(3, GL_FLOAT, 0, NULL);

		glBindBuffer(GL_ARRAY_BUFFER, mesh->id_uvs);
		glTexCoordPointer(2, GL_FLOAT, 0, NULL);

		if (material)
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, material->texture_id);
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->id_indices);
		glDrawElements(GL_TRIANGLES, mesh->num_indices, GL_UNSIGNED_INT, NULL);

		glDisable(GL_TEXTURE_2D);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		if (trans)
			glPopMatrix();
	}
}