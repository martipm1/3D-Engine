#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <string>

class GameObject;

enum component_type
{
	c_transform,
	c_mesh,
	c_material
};

class Component
{
public:
	Component(component_type _type, std::string _name, GameObject* _parent) : type(_type), name(_name), parent(_parent)
	{
		active = true;
	}

	virtual void Update()
	{}

	virtual void DeleteComponent()
	{}
	
	void SetActive(bool act)
	{
		active = act;
	}

	virtual void OnProperties()
	{}

	component_type type;
	std::string name;
	bool active;
	GameObject* parent;
};

#endif // !__COMPONENT_H__

