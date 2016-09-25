#pragma once
#include "Menus.h"

class MenuProject : public Menu
{
public:
	MenuProject();
	virtual ~MenuProject();

	const char* name;

	int pos;
	float fps_log[100];

	void Render();
};