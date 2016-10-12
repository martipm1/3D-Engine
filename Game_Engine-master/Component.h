#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <string>

enum component_type
{
	c_transform,
	c_mesh,
	c_material
};

class Component
{
public:
	component_type type;
	std::string name;
	bool active;

	Component(component_type _type, std::string _name) : type(_type), name(_name)
	{}

	virtual void Update()
	{}
	
	void Enable()
	{
		active = true;
	}

	virtual void Disable()
	{
		active = false;
	}
};

#endif // !__COMPONENT_H__

