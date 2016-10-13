#ifndef __COMPONENTMESH_H__
#define __COMPONENTMESH_H__

#include "Component.h"
#include <vector>
struct Mesh_str;
class GameObject;

class ComponentMesh : public Component
{
public:
	Mesh_str* mesh;
	GameObject* parent;

	ComponentMesh(component_type type, Mesh_str* _mesh, GameObject* parent);
	~ComponentMesh();

	void Update();
};

#endif //__COMPONENTMESH_H__