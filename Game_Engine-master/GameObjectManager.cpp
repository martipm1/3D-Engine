#include "GameObjectManager.h"

GameObjectManager::GameObjectManager(Application* app, bool start_enabled = true) : Module(app, start_enabled)
{
	root = nullptr;
}

GameObjectManager::~GameObjectManager()
{}

bool GameObjectManager::Start()
{}

update_status GameObjectManager::Update(float dt)
{
	if (root->active)
		root->Update();
}

bool GameObjectManager::CleanUp()
{
	delete[] root;
}

GameObject* GameObjectManager::CreateGameObject(GameObject* parent = nullptr, std::string name, info components...)
{
	GameObject* object = new GameObject(parent, name, info components);

	return object;
}

void DeleteGameObject(GameObject* object)
{
	object->Delete();
}