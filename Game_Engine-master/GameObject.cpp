#include "GameObject.h"
#include "Component.h"
#include "ComponentMesh.h"
#include "ComponentTransform.h"
#include "ComponentMaterial.h"
#include "GameObjectManager.h"

GameObject::GameObject(std::string _name, GameObject* _parent)
{
	name.resize(30);

	parent = _parent;
	if(parent != nullptr)
		parent->childs.push_back(this);

	name = _name;
}

GameObject::~GameObject()
{
	//delete parent;
	//delete components;
	//delete childs;
	//delete name;
}

void GameObject::Update()
{
	std::vector<GameObject*>::iterator tmp1 = childs.begin();

	for (tmp1; tmp1 != childs.end(); tmp1++)
	{
		(*tmp1)->Update();
	}

	std::vector<Component*>::iterator tmp2 = components.begin();
	
	for (tmp2; tmp2 != components.end(); tmp2++)
	{
		(*tmp2)->Update();
	}
	
}

GameObject* GameObject::GetParent()
{
	return parent;
}

std::vector<GameObject*> GameObject::GetChilds()
{
	return childs;
}

Component* GameObject::AddComponent(component_type type, Mesh_str* _mesh, GameObject* _parent)
{
	if (_mesh)
	{
		ComponentMesh* mesh = new ComponentMesh(type, _mesh, _parent);
		components.push_back(mesh);

		return mesh;
	}

	//If never happens to get to this line, something went wrong!
	return nullptr;
}

Component* GameObject::AddComponent(component_type type, float3 pos, float3 scale, Quat rot, GameObject* _parent)
{
	ComponentTransform* transform = new ComponentTransform(type, pos, scale, rot, _parent);
	components.push_back(transform);
	
	return transform;
}

Component* GameObject::AddComponent(component_type type, size_t id, GameObject* _parent)
{
	ComponentMaterial* material = new ComponentMaterial(type, id, _parent);
	components.push_back(material);

	return material;
}

Component* GameObject::FindComponent(component_type _type)
{
	//This is messed up, somehow...
	std::vector<Component*>::iterator tmp = components.begin();

	for (tmp; tmp != components.end(); tmp++)
	{
		if ((*tmp)->type == _type)
			return (*tmp);
	}

	return NULL;
}