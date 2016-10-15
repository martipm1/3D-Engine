#include "MenuHierarchy.h"
#include "GameObject.h"
#include "Imgui/imgui.h"

MenuHierarchy::MenuHierarchy(const char* _name, GameObject* _hierarchy_root)
{
	name = _name;
	hierarchy_root = _hierarchy_root;
	active = false;
	width = 300;
	height = 500;
	pos_x = 0;
	pos_y = 30;
	pos = 0;
}

MenuHierarchy::~MenuHierarchy()
{
	hierarchy_root = nullptr;
}

void MenuHierarchy::Render()
{
	ImGui::Begin(name, &active,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove);

	//Display all nodes

	ImGui::End();
}