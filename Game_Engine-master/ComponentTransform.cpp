#include "ComponentTransform.h"
#include "GameObject.h"

ComponentTransform::ComponentTransform(component_type type, float3 pos, float3 scale, Quat rot, GameObject* _parent) : Component(type, "Transformation", _parent)
{
	position = pos;
	scalation = scale;
	rotation = rot;

	local_mat = local_mat.FromTRS(position, rotation, scalation);
}

ComponentTransform::~ComponentTransform()
{}

void ComponentTransform::Update()
{

}

float4x4 ComponentTransform::GetMatrix()
{
	float4x4 mat;
	
	return mat;
}