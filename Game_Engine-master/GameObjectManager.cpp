#include "Application.h"
#include "GameObjectManager.h"
#include "GameObject.h"

GameObjectManager::GameObjectManager(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

GameObjectManager::~GameObjectManager()
{}

bool GameObjectManager::Start()
{
	root = nullptr;

	return true;
}

update_status GameObjectManager::Update(float dt)
{
	if (root->active)
		root->Update();

	return UPDATE_CONTINUE;
}

bool GameObjectManager::CleanUp()
{
	//delete[] root;
	return true;
}

GameObject* GameObjectManager::CreateGameObject(std::string name, GameObject* parent = nullptr)
{ 
	GameObject* object = new GameObject(name, parent);

	if (!root && parent == nullptr)
		root = object;

	return object;
}

void GameObjectManager::DeleteGameObject(GameObject* object)
{
	//object->Delete();
}