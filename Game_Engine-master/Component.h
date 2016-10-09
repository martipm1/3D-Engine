#ifndef __COMPONENT_H__
#define __COMPONENT_H__

enum component_type
{
	c_transform,
	c_mesh,
	c_material
};

class Component
{
	component_type type;
	
	//PATTERN

	virtual void Enable();
	virtual void Update();
	virtual void Disable();
};

#endif // __COMPONENT_H__

