#ifndef __COMPONENTMESH_H__
#define __COMPONENTMESH_H__

#include "Component.h"
#include "ModuleMesh.h"
#include "MathGeoLib\Geometry\AABB.h"
#include <vector>
struct Mesh_str;
class GameObject;

class ComponentMesh : public Component
{
public:
	Mesh_str mesh;
	GameObject* parent;
	AABB bbox;

	ComponentMesh(component_type type, Mesh_str _mesh, GameObject* parent);
	~ComponentMesh();

	void Update();
	void DeleteComponent();
	void OnProperties();
};

#endif //__COMPONENTMESH_H__