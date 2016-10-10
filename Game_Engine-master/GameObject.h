#ifndef __GAMEOBJECT_H__
#define __GMAEOBJECT_H__

#include <vector>
//#include "ModuleMesh.h"
#include "Component.h"

struct Mesh_str;

class GameObject
{
	public:
		GameObject(std::string _name, GameObject* _parent = nullptr);
		~GameObject();
		void Update();
		GameObject* GetParent();
		//add Mesh component
		Component* AddComponent(component_type type, std::vector<Mesh_str> mesh);
		//add Transform component
		Component* AddComponent(component_type type, int i);
		//add Material component
		Component* AddComponent(component_type type, float y);
		Component* FindComponent(component_type type);
	
	public:
		GameObject* parent;
		std::string name;
		std::vector<Component*> components;
		std::vector<GameObject*> childs;
		bool active;
};

#endif // __GAMEOBJECT_H__

