#include "ComponentMesh.h"
//Geometry stuff, shouldn't be here ONLY TESTING!
#include "Glew\include\glew.h"
#include "SDL\include\SDL_opengl.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib, "glu32.lib")    /* link OpenGL Utility lib     */
#pragma comment (lib, "opengl32.lib") /* link Microsoft OpenGL lib   */
#pragma comment (lib, "Glew/libx86/glew32.lib") 
//Geometry stuff, shouldn't be here

ComponentMesh::ComponentMesh(component_type type, std::vector<Mesh_str> _mesh) : Component(type, "Mesh")
{
	mesh = _mesh;
}

ComponentMesh::~ComponentMesh()
{

}

void ComponentMesh::Enable()
{
	if (!active)
		active = !active;
}

void ComponentMesh::Update()
{
	if (active)
	{
		//Draw the geometry (mesh) :^D
		std::vector<Mesh_str>::iterator it = mesh.begin();
		while (it != mesh.end())
		{
			glEnableClientState(GL_VERTEX_ARRAY);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (*it).id_indices);
			glVertexPointer(3, GL_FLOAT, 0, NULL);
			glDrawElements(GL_TRIANGLES, (*it).num_indices, GL_UNSIGNED_INT, NULL);
			glDisableClientState(GL_VERTEX_ARRAY);

			it++;
		}
	}
}

void ComponentMesh::Disable()
{
	if (active)
		active = !active;
}