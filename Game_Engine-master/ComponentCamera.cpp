#include "ComponentCamera.h"

ComponentCamera::ComponentCamera(component_type type, GameObject* _parent) : Component(type, "Camera", _parent)
{
	frustum.nearPlaneDistance = 5;
	frustum.farPlaneDistance = 200;
	
}

ComponentCamera::~ComponentCamera()
{

}
