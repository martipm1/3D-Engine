#include "MenuProject.h"
#include "Imgui/imgui.h"


// ------------------------------------------------------------
MenuProject::MenuProject() : Menu(Menu_About)
{
	width = 600;
	height = 500;
	pos_x = 350;
	pos_y = 450;
	active = false;
	name = "PROJECT SETTINGS";
	pos = 0;
}

// ------------------------------------------------------------
MenuProject::~MenuProject()
{}

// ------------------------------------------------------------
void MenuProject::Render()
{
	ImGui::Begin(name, &active,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse);

	ImGui::CollapsingHeader("Application");

	ImGui::CollapsingHeader("Window");

	char title[25];
	sprintf_s(title, "Framerate %.1f", fps_log[pos-1]);
	ImGui::PlotHistogram("##framerate", &fps_log[0], pos, 0, title, 0, 100, ImVec2(310, 100));
	//sprintf_s(title, "Miliseconds %.1f", fps_log[pos - 1]);
	//ImGui::PlotHistogram("##milliseconds", &fps_log[0], fps_log[pos], 0, title, 0, 100, ImVec2(310, 100));

	ImGui::End();
}