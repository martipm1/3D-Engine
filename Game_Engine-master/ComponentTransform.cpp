#include "ComponentTransform.h"
#include "GameObject.h"
#include "Imgui\imgui.h"
#include "MathGeoLib\MathGeoLib.h"

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
{}

void ComponentTransform::DeleteComponent()
{
	parent = nullptr;
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

void ComponentTransform::OnProperties()
{
	if (ImGui::CollapsingHeader("GameObject Transform", ImGuiTreeNodeFlags_DefaultOpen))
	{
		//May not be a good idea to let ComponentTransform be activated/deactivated!

		ImGui::TextColored(ImVec4(255, 255, 255, 255), "Position:");
		if (ImGui::DragFloat3("Pos", position.ptr()))
		{
			SetPosition(position);
		}
		ImGui::TextColored(ImVec4(255, 255, 255, 255), "Scalation:");
		if (ImGui::DragFloat3("Scale", scalation.ptr()))
		{
			SetScale(scalation);
		}
		ImGui::TextColored(ImVec4(255, 255, 255, 255), "Rotation:");
		float3 euler_rot = rotation.ToEulerXYX();
		if (ImGui::DragFloat3("Rotation", euler_rot.ptr(), 1.0f, -360.0f, 360.0f))
		{
			SetRotation(euler_rot);
		}

	}
}

void ComponentTransform::SetPosition(float3 pos)
{
	position = pos;

	local_mat = local_mat.FromTRS(position, rotation, scalation);
}

void ComponentTransform::SetScale(float3 scale)
{
	scalation = scale;

	local_mat = local_mat.FromTRS(position, rotation, scalation);
}

void ComponentTransform::SetRotation(float3 rot)
{
	float3 rot_degrees = DegToRad(rot);

	rotation = rotation.FromEulerXYZ(rot_degrees.z, rot_degrees.y, rot_degrees.x);
		
	local_mat = local_mat.FromTRS(position, rotation, scalation);
}