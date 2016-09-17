#include "Globals.h"
#include "Application.h"
#include "ModuleEditor.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_sdl_gl3.h"
#include "ImGui/gl3w.h"

ModuleEditor::ModuleEditor(Application* app, bool start_enabled) : Module(app, start_enabled)
{}

ModuleEditor::~ModuleEditor()
{}

// Load assets
bool ModuleEditor::Init()
{
	bool ret = true;
	gl3wInit();

	ImGui_ImplSdlGL3_Init(App->window->window);
	return ret;
}

// Clean up ImGui
bool ModuleEditor::CleanUp()
{
	LOG("Unloading Intro scene");
	ImGui_ImplSdlGL3_Shutdown();
	return true;
}
update_status ModuleEditor::PreUpdate(float dt)
{
	ImGui_ImplSdlGL3_NewFrame(App->window->window);

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleEditor::Update(float dt)
{
	static bool show_test_window = true;
	static bool show_menu = true;

	update_status ret = UPDATE_CONTINUE;

	if (show_test_window)
	{
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}

	if (show_menu == true)
	{
		if (ImGui::BeginMainMenuBar())
		{
			bool selected = false;

			if (ImGui::BeginMenu("File"))
			{
				ImGui::MenuItem("New");
				ImGui::MenuItem("Save");
				ImGui::MenuItem("Load");

				if (ImGui::MenuItem("Quit"))
					ret = UPDATE_STOP;

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Window"))
			{
				ImGui::MenuItem("New window");

				if (ImGui::MenuItem("Open test window"))
					show_test_window = true;

				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();
		}
	}


	ImGui::Render();

	return ret;
}