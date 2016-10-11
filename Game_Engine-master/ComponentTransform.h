#ifndef __COMPONENTTRANSFORM_H__
#define __COMPONENTTRANSFORM_H__

#include "Component.h"
#include <vector>

class ComponentTransform : public Component
{
	void Enable();
	void Update();
	void Disable();

	std::vector<float> pos;
	std::vector<float> scale;
	//glQuaternion rotation;
};

#endif // !__COMPONENTTRANSFORM_H__

