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

float4x4 ComponentTransform::GetRenderingMatrix()
{
	float4x4 mat = local_mat;
	
	if (parent->parent != nullptr)
	{
		ComponentTransform* trans = (ComponentTransform*)parent->parent->FindComponent(c_transform);
		if(trans)
			mat = trans->GetRenderingMatrix() * mat;
	}

	return mat;
}