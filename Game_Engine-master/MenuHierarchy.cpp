#include "MenuHierarchy.h"
#include "GameObject.h"
#include "Imgui/imgui.h"

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
	for (std::vector<GameObject*>::const_iterator object = parent->childs.begin(); object != parent->childs.end(); ++object)
	{
		uint flags = 0;

		if ((*object) == focused_game_object)
			flags = ImGuiTreeNodeFlags_Selected;

		if ((*object)->childs.size() > 0)
		{
			if (ImGui::TreeNodeEx((*object)->name.data(), flags))
			{
				if (ImGui::IsItemClicked(0))
				{
					focused_game_object = (*object);
				}

				DisplayChildNodes((*object));

				ImGui::TreePop();
			}
		}
		else
		{
			if (ImGui::TreeNodeEx((*object)->name.data(), flags | ImGuiTreeNodeFlags_Leaf))
			{
				if (ImGui::IsItemClicked(0))
				{
					focused_game_object = (*object);
				}
				ImGui::TreePop();
			}
		}
	}
}

void MenuHierarchy::DisplayFocusedGameObject()
{

}

void MenuHierarchy::Activate(GameObject* _hierarchy_root)
{
	hierarchy_root = _hierarchy_root;
	active = true;
}