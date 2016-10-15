#ifndef __MENUHIERARCHY_H__
#define __MENUHIERARCHY_H__
#include "Menus.h"

class GameObject;

class MenuHierarchy : public Menu
{
public:
	MenuHierarchy(const char* _name, GameObject* _hierarchy_root);
	~MenuHierarchy();

	const char* name;
	GameObject* hierarchy_root;
	GameObject* focused_game_object;
	int pos;

	void Render();
	void DisplayChildNodes(GameObject* parent);
	void DisplayFocusedGameObject();
	void Activate(GameObject* _hierarchy_root);
	void DeleteMenu();
};

#endif __MENUHIERARCHY_H__
