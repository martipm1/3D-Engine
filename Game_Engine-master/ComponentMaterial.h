#ifndef __COMPONENTMATERIAL_H__
#define __COMPONENTMATERIAL_H__

#include "Component.h"

class GameObject;

class ComponentMaterial : public Component
{
public:
	ComponentMaterial(component_type type, size_t id, GameObject* _parent);
	~ComponentMaterial();

	void Update();
	void DeleteComponent();
	void OnProperties();
	
	size_t texture_id;
};

#endif // !__COMPONENTMATERIAL_H__
