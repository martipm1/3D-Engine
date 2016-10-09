#ifndef __GAMEOBJECT_H__
#define __GMAEOBJECT_H__

#include "Globals.h"
#include <vector>
#include "Component.h"

class GameObject
{
	public:
		void Update();
		GameObject* GetParent();
		Component* AddComponent(component_type type);
		Component* FindComponent(component_type type);
	
	public:
		GameObject* parent;
		char* name;
		std::vector<Component*> components;
		std::vector<GameObject*> childs;

};

#endif // __GAMEOBJECT_H__

