#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(GameObject* _parent = nullptr, std::string _name, info _components)
{
	parent = _parent;
	name = _name;

	if (transform)
		components.push_back(AddComponent(c_transform, info));
	if (mesh)
		components.push_back(AddComponent(c_mesh, info));
	if (material)
		components.push_back(AddComponent(c_material, info));
}

GameObject::~GameObject()
{
	delete parent;
	delete components;
	delete childs;
	delete name;
}

void GameObject::Update()
{
	for (int i = 0; i < childs.size(); i++)
	{
		childs[i]->Update();
	}
	for (int i = 0; i < components.size(); i++)
	{
		//watch out, cause it ain't declared! Gotta find a way to call pertinent update!
		components[i]->Update();
	}
}

GameObject* GameObject::GetParent()
{
	return parent;
}

Component* GameObject::AddComponent(component_type type, info component)
{
	switch (type)
	{
	case c_transform:
		ComponentTransform* transform = new ComponentTransform();
		return transform;

	case c_mesh:
		ComponentMesh* mesh = new ComponentMesh();
		return mesh;

	case c_material:
		ComponentMaterial* material = new ComponentMaterial();
		return material;
	}

	//If never happens to get to this line, something went wrong!
	return nullptr;
}

Component* GameObject::FindComponent(component_type _type)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->type == _type)
			return components[i];
	}

	//If never happens to get to this line, something went wrong!
	return nullptr;
}