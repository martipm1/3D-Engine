#ifndef __COMPONENTMESH_H__
#define __COMPONENTMESH_H__

#include "Component.h"
#include <vector>
#include "ModuleMesh.h"

class ComponentMesh : public Component
{
public:
	std::vector<Mesh_str> mesh;

	ComponentMesh(component_type type, std::vector<Mesh_str> _mesh);
	~ComponentMesh();

	void Enable();
	void Update();
	void Disable();
};

#endif //__COMPONENTMESH_H__