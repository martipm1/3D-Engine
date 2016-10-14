#include "Application.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "Imgui\imgui.h"
#include <vector>

GameObjectManager::GameObjectManager(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	root = new GameObject("Root_node", nullptr);
}

GameObjectManager::~GameObjectManager()
{}

bool GameObjectManager::Start()
{
	return true;
}

update_status GameObjectManager::Update(float dt)
{
	if (root != nullptr)
	{
		if (root->active)
			root->Update();
	}

	//DisplayGameObjectsWindow();

	return UPDATE_CONTINUE;
}

bool GameObjectManager::CleanUp()
{
	//delete[] root;
	return true;
}

GameObject* GameObjectManager::CreateGameObject(std::string name, GameObject* parent = nullptr)
{ 
	if (parent == nullptr)
		parent = root;

	GameObject* object = new GameObject(name, parent);

	return object;
}

void GameObjectManager::DeleteGameObject(GameObject* object)
{
	//object->Delete();
}

void GameObjectManager::DisplayGameObjectsWindow()
{
	ImGui::Begin("Scene Hierarchy");

	for (std::vector<GameObject*>::const_iterator object = root->childs.begin(); object != root->childs.end(); ++object)
	{
		uint flags = 0;

		if ((*object) == focus_game_object)
			flags = ImGuiTreeNodeFlags_Selected;

		if ((*object)->childs.size() > 0)
		{
			if (ImGui::TreeNodeEx((*object)->name.data(), flags))
			{
				if (ImGui::IsItemClicked(0))
				{
					focus_game_object = (*object);
				}

				//DisplayGameObjectsChilds((*object)->GetChilds());

				ImGui::TreePop();
			}
		}
		else
		{
			if (ImGui::TreeNodeEx((*object)->name.data(), flags | ImGuiTreeNodeFlags_Leaf))
			{
				if (ImGui::IsItemClicked(0))
				{
					focus_game_object = (*object);
				}
				ImGui::TreePop();
			}
		}
	}

	ImGui::End();
}

void GameObjectManager::DisplaySelectedGameObjectWindow()
{

}