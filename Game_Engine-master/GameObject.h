#ifndef __GAMEOBJECT_H__
#define __GMAEOBJECT_H__

#include "Globals.h"
#include "MathGeoLib\Math\float3.h"
#include "MathGeoLib\Math\Quat.h"
#include <vector>
class Component;
class MeshComponent;
struct Mesh_str;
enum component_type;

class GameObject
{
	public:
		GameObject(std::string _name, GameObject* _parent = nullptr);
		~GameObject();

		void Update();
		GameObject* GetParent();
		//add Mesh component
		Component* AddComponent(component_type type, Mesh_str* mesh);
		//add Transform component
		Component* AddComponent(component_type type, float3 pos, float3 scale, Quat rot);
		//add Material component, provisional
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

