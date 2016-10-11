#ifndef __GAMEOBJECTMANAGER_H__
#define __GAMEOBJECTMANAGER_H__

#include "Module.h"
class GameObject;

class GameObjectManager: public Module
{
public:
	GameObjectManager(Application* app, bool start_enabled = true);
	~GameObjectManager();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	//Should recieve specific data to create the object*
	GameObject* CreateGameObject(std::string name, GameObject* parent);
	void DeleteGameObject(GameObject* object);

	GameObject* root;
};

#endif // !__GAMEOBJECTMANAGER_H__

