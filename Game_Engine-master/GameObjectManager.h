#ifndef __GAMEOBJECTMANAGER_H__
#define __GAMEOBJECTMANAGER_H__

#include "GameObject.h"
#include "Module.h"
#include <string>

class GameObjectManager: public Module
{
	GameObjectManager(Application* app, bool start_enabled = true);
	~GameObjectManager();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	//Should recieve specific data to create the object*
	GameObject* CreateGameObject(GameObject* parent = nullptr, std::string name);
	void DeleteGameObject(GameObject* object);

	GameObject* root;
};

#endif // ! __GAMEOBJECTMANAGER_H__

