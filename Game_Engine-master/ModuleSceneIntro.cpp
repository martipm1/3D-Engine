#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "RNG.h"

//Geometry stuff, shouldn't be here
#include "Glew\include\glew.h"
#include "SDL\include\SDL_opengl.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib, "glu32.lib")    /* link OpenGL Utility lib     */
#pragma comment (lib, "opengl32.lib") /* link Microsoft OpenGL lib   */
#pragma comment (lib, "Glew/libx86/glew32.lib") 
//Geometry stuff, shouldn't be here

//Assimp stuff, shouldn't be here
#include "Assimp\include\cimport.h"
#include "Assimp\include\scene.h"
#include "Assimp\include\postprocess.h"
#include "Assimp\include\cfileio.h"

#pragma comment (lib, "Assimp\libx86\assimp.lib")
//Assimp stuff, shouldn't be here

Struct Mesh{
}


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");

	bool ret = true;

	GLenum gl_enum = glewInit();

	static const GLfloat my_D_is_Tasty[] = {
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};


	glGenBuffers(1, (GLuint*)&(my_id));
	glBindBuffer(GL_ARRAY_BUFFER, my_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(my_D_is_Tasty) * 3, &my_D_is_Tasty, GL_STATIC_DRAW);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update(float dt)
{
	Plane(0, 1, 0, 0).Render();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.f, 0.f, 5.f);
	glVertex3f(1.f, 0.f, 5.f);
	glVertex3f(1.f, 0.f, 6.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, 0.f, 6.f);
	glVertex3f(0.f, 0.f, 6.f);
	glVertex3f(0.f, 0.f, 5.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, 1.f, 5.f);
	glVertex3f(0.f, 1.f, 5.f);
	glVertex3f(0.f, 1.f, 6.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, 1.f, 5.f);
	glVertex3f(0.f, 1.f, 6.f);
	glVertex3f(1.f, 1.f, 6.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, 0.f, 6.f);
	glVertex3f(1.f, 1.f, 6.f);
	glVertex3f(0.f, 1.f, 6.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(0.f, 0.f, 6.f);
	glVertex3f(1.f, 0.f, 6.f);
	glVertex3f(0.f, 1.f, 6.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, 0.f, 5.f);
	glVertex3f(0.f, 1.f, 5.f);
	glVertex3f(1.f, 1.f, 5.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(0.f, 0.f, 5.f);
	glVertex3f(0.f, 1.f, 5.f);
	glVertex3f(1.f, 0.f, 5.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, 0.f, 5.f);
	glVertex3f(1.f, 1.f, 5.f);
	glVertex3f(1.f, 1.f, 6.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, 1.f, 6.f);
	glVertex3f(1.f, 0.f, 6.f);
	glVertex3f(1.f, 0.f, 5.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(0.f, 0.f, 5.f);
	glVertex3f(0.f, 0.f, 6.f);
	glVertex3f(0.f, 1.f, 6.f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(0.f, 1.f, 6.f);
	glVertex3f(0.f, 1.f, 5.f);
	glVertex3f(0.f, 0.f, 5.f);
	glEnd();

	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, my_id);
	glVertexPointer(3, GL_FLOAT, 0, NULL);

	// ... draw other buffers

	glDrawArrays(GL_TRIANGLES, 0, 36 * 3);
	glDisableClientState(GL_VERTEX_ARRAY);

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	int a = 0;
}
