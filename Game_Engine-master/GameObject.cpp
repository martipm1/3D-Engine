#include "GameObject.h"
#include "Component.h"
#include "ComponentMesh.h"
#include "GameObjectManager.h"

GameObject::GameObject(std::string _name, GameObject* _parent)
{
	parent = _parent;
	if(parent)
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

Component* GameObject::AddComponent(component_type type, Mesh_str* _mesh)
{
	if (_mesh)
	{
		ComponentMesh* mesh = new ComponentMesh(type, _mesh);
		components.push_back(mesh);

		return mesh;
	}

	//If never happens to get to this line, something went wrong!
	return nullptr;
}

Component* GameObject::AddComponent(component_type type, int i)
{
	//if (_mesh)
	//{
	//	ComponentMesh* mesh = new ComponentMesh();
	//	components.push_back(mesh);
	//
	//	return mesh;
	//}
	//
	//If never happens to get to this line, something went wrong!
	return nullptr;
}

Component* GameObject::AddComponent(component_type type, float y)
{
	//if (_mesh)
	//{
	//	ComponentMesh* mesh = new ComponentMesh();
	//	components.push_back(mesh);
	//
	//	return mesh;
	//}
	//
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