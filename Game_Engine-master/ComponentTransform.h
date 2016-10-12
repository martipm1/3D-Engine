#ifndef __COMPONENTTRANSFORM_H__
#define __COMPONENTTRANSFORM_H__

#include "Component.h"
#include "MathGeoLib\Math\float3.h"
#include "MathGeoLib\Math\Quat.h"

class ComponentTransform : public Component
{
public:
	ComponentTransform(component_type type, float3 pos, float3 scale, Quat rot);
	~ComponentTransform();

	void Update();
	
	component_type type;
	float3 position;
	float3 scalation;
	Quat rotation;
};

#endif // !__COMPONENTTRANSFORM_H__

