#include "MenuAbout.h"
#include "Imgui/imgui.h"

// ------------------------------------------------------------
MenuAbout::MenuAbout() : Menu(Menu_About)
{
	width = 600;
	height = 90;
	pos_x = 350;
	pos_y = 450;
	active = false;
}

// ------------------------------------------------------------
MenuAbout::~MenuAbout()
{}

// ------------------------------------------------------------
void MenuAbout::Render()
{
	ImGui::Begin("", &active,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse);

	ImGui::Text("3D game engine made for a college's subject.");
	ImGui::Text("By dat boi.");
	ImGui::Separator();
	ImGui::Text("This Engine is licensed under the Public Domain, see LICENSE for more information.");
	ImGui::End();
}
