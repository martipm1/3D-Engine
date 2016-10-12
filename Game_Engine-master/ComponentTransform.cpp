#include "ComponentTransform.h"

ComponentTransform::ComponentTransform(component_type type, float3 pos, float3 scale, Quat rot) : Component(type, "Transformation")
{
	position = pos;
	scalation = scale;
	rotation = rot;
}

ComponentTransform::~ComponentTransform()
{}

void ComponentTransform::Update()
{

}