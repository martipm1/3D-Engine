#ifndef __GAMEOBJECT_H__
#define __GMAEOBJECT_H__

#include "Globals.h"
#include <vector>
#include "Component.h"

class GameObject
{
	public:
		GameObject(GameObject* parent = nullptr, std::string name, info components);
		~GameObject();
		void Update();
		GameObject* GetParent();
		Component* AddComponent(component_type type, info component);
		Component* FindComponent(component_type type, info component);
	
	public:
		GameObject* parent;
		std::string name;
		std::vector<Component*> components;
		std::vector<GameObject*> childs;
		bool active;
};

#endif // __GAMEOBJECT_H__

