#include "ComponentTransform.h"
#include "GameObject.h"

ComponentTransform::ComponentTransform(component_type type, float3 pos, float3 scale, Quat rot, GameObject* _parent) : Component(type, "Transformation", _parent)
{
	parent = _parent;
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
	
	if (parent->parent)
	{
		ComponentTransform* trans = (ComponentTransform*)parent->FindComponent(c_transform);
		if (trans)
		{
			mat = trans->local_mat;
			mat = mat * local_mat;
		}
	}
	else
		mat = local_mat;

	return mat;
}