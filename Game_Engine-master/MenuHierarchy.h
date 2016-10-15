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
	int pos;

	void Render();
};

#endif __MENUHIERARCHY_H__
