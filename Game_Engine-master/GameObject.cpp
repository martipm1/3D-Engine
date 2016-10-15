#include "GameObject.h"
#include "Component.h"
#include "ComponentMesh.h"
#include "ComponentTransform.h"
#include "ComponentMaterial.h"
#include "GameObjectManager.h"
#include "ModuleMesh.h"

GameObject::GameObject(std::string _name, GameObject* _parent)
{
	name.resize(30);

	parent = _parent;
	if(parent != nullptr)
		parent->childs.push_back(this);

	name = _name;
}

GameObject::~GameObject()
{}

void GameObject::Update()
{
	if (active)
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
}

void GameObject::Delete()
{
	parent = nullptr;
	
	std::vector<GameObject*>::iterator tmp1 = childs.begin();
	for (tmp1; tmp1 != childs.end(); tmp1++)
	{
		(*tmp1)->Delete();
		(*tmp1) = nullptr;
	}

	std::vector<Component*>::iterator tmp2 = components.begin();
	for (tmp2; tmp2 != components.end(); tmp2++)
	{
		(*tmp2)->DeleteComponent();
		(*tmp2) = nullptr;
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

void GameObject::SetActive(bool act)
{
	active = act;

	std::vector<GameObject*>::iterator tmp = childs.begin();

	for (tmp; tmp != childs.end(); tmp++)
	{
		(*tmp)->SetActive(act);
	}
}

Component* GameObject::AddComponent(component_type type, Mesh_str _mesh, GameObject* _parent)
{

	ComponentMesh* mesh = new ComponentMesh(type, _mesh, _parent);
	components.push_back(mesh);
	
	return mesh;
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