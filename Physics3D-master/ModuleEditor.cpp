#include "Application.h"
//#include "Config.h" 
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_SDL_GL3_IMPLEMENTATION
#include "imgui-master/imgui.h"
#include "imgui-master/examples/sdl_opengl3_example/imgui_impl_sdl_gl3.h"
//#include "OpenGL.h"


ModuleEditor::ModuleEditor(Application* app, bool start_enabled) : Module(app, start_enabled)
{}

// Destructor
ModuleEditor::~ModuleEditor()
{}

bool ModuleEditor::Init()
{
	LOG("Init editor gui with imgui lib");

	ImGui_ImplSdlGL3_Init(App->window->window);

	return true;
}

update_status ModuleEditor::PreUpdate(float dt)
{
	ImGui_ImplSdlGL3_NewFrame(App->window->window);

return UPDATE_CONTINUE;
}

update_status ModuleEditor::Update(float dt)
{
	static bool show_test_window = true;

	static bool show_another_window = false;

	static  ImVec4 clear_color = ImColor(114, 144, 154);
	{
		static float f = 0.0f;

		ImGui::Text("Hello, world!");

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

		ImGui::ColorEdit3("clear color", (float*)&clear_color);

		if (ImGui::Button("Test Window")) show_test_window ^= 1;

		if (ImGui::Button("Another Window")) show_another_window ^= 1;

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}

		if (show_test_window)
		{
			ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);

			ImGui::ShowTestWindow(&show_test_window);
		}

		return UPDATE_CONTINUE;
}

bool ModuleEditor::CleanUp()
{
	LOG("Freeing editor gui");

	ImGui_ImplSdlGL3_Shutdown();

	return true;
}

void ModuleEditor::HandleInput(SDL_Event* event)
{
	ImGui_ImplSdlGL3_ProcessEvent(event);
}

void ModuleEditor::Draw()
{
	ImGui::Render();
}

bool ModuleEditor::IsHovered()
{
	return ImGui::IsAnyItemHovered();
}