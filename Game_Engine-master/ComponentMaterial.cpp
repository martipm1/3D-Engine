#include "ComponentMaterial.h"

ComponentMaterial::ComponentMaterial(component_type type, size_t id, GameObject* _parent) : Component(type, "Material", _parent)
{
	parent = _parent;
	texture_id = id;
}

ComponentMaterial::~ComponentMaterial()
{}

void ComponentMaterial::Update()
{
	return;
}