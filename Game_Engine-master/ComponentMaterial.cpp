#include "ComponentMaterial.h"
#include "Imgui\imgui.h"

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

void ComponentMaterial::DeleteComponent()
{
	parent = nullptr;
}

void ComponentMaterial::OnProperties()
{
	if (ImGui::CollapsingHeader("GameObject Material", ImGuiTreeNodeFlags_DefaultOpen))
	{
		bool active_state = active;
		if (ImGui::Checkbox("MaterialIsActive", &active_state))
		{
			SetActive(active_state);
		}

		ImGui::Image((ImTextureID)texture_id, ImVec2(250, 250));
	}
}