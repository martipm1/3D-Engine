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

	Component(component_type _type, std::string _name)
	{
		type = _type;
		name = _name;
	}

	virtual void Enable()
	{}
	virtual void Update()
	{}
	virtual void Disable()
	{}
};

#endif // __COMPONENT_H__

