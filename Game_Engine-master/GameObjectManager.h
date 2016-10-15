#ifndef __GAMEOBJECTMANAGER_H__
#define __GAMEOBJECTMANAGER_H__

#include "Globals.h"
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

	GameObject* CreateGameObject(std::string name, GameObject* parent);
	void DeleteGameObject(GameObject* object);

	GameObject* root;
	GameObject* focus_game_object;
};

#endif // !__GAMEOBJECTMANAGER_H__

