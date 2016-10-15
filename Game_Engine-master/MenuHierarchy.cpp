#include "MenuHierarchy.h"
#include "GameObject.h"
#include "Imgui/imgui.h"
#include <vector>

MenuHierarchy::MenuHierarchy(const char* _name, GameObject* _hierarchy_root)
{
	name = _name;
	hierarchy_root = _hierarchy_root;
	focused_game_object = nullptr;
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
	focused_game_object = nullptr;
}

void MenuHierarchy::Render()
{
	//Hierarchy
	ImGui::Begin(name, &active,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove);

	if(hierarchy_root != nullptr)
		DisplayChildNodes(hierarchy_root);

	if (focused_game_object != nullptr)
	{
		DisplayFocusedGameObject();
	}

	ImGui::End();
}

void MenuHierarchy::DisplayChildNodes(GameObject* parent)
{
	for (std::vector<GameObject*>::const_iterator child = parent->childs.begin(); child != parent->childs.end(); ++child)
	{
		uint flags = 0;

		if ((*child) == focused_game_object)
			flags = ImGuiTreeNodeFlags_Selected;

		if ((*child)->childs.size() > 0)
		{
			if (ImGui::TreeNodeEx((*child)->name.data(), flags))
			{
				if (ImGui::IsItemClicked(0))
				{
					focused_game_object = (*child);
				}
				DisplayChildNodes((*child));
				
				ImGui::TreePop();
			}
		}
		else
		{
			if (ImGui::TreeNodeEx((*child)->name.data(), flags | ImGuiTreeNodeFlags_Leaf))
			{
				if (ImGui::IsItemClicked(0))
				{
					focused_game_object = (*child);
				}
				ImGui::TreePop();
			}
		}
	}
}

void MenuHierarchy::DisplayFocusedGameObject()
{
	ImGui::Begin("GameObject Propertires", &active, ImVec2(300, 500), -1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
	//Active
	bool active_state = focused_game_object->active;

	if (ImGui::Checkbox("Active", &active_state))
	{
		focused_game_object->SetActive(active_state);
	}

	//Name
	ImGui::InputText("###goname", focused_game_object->name._Myptr(), focused_game_object->name.capacity());

	//Components
	const std::vector<Component*>* components = &focused_game_object->components;
	for (std::vector<Component*>::const_iterator component = (*components).begin(); component != (*components).end(); ++component)
	{
		//(*component)->OnInspector();
	}

	ImGui::End();
}

void MenuHierarchy::Activate(GameObject* _hierarchy_root)
{
	hierarchy_root = _hierarchy_root;
	active = true;
}