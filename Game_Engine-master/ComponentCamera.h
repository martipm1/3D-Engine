#ifndef __COMPONENTCAMERA_H__
#define __COMPONENTCAMERA_H__

#include "Component.h"
#include "ModuleWindow.h"
#include "MathGeoLib\Geometry\Frustum.h"

class ComponentCamera : public Component
{
	public:
		Frustum frustum;
		float VFOV_value;

		ComponentCamera(component_type type, GameObject* _parent);
		~ComponentCamera();
};

#endif __COMPONENTCAMERA_H__
