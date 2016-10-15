#ifndef __COMPONENTTRANSFORM_H__
#define __COMPONENTTRANSFORM_H__

#include "Component.h"
#include "MathGeoLib\Math\float3.h"
#include "MathGeoLib\Math\Quat.h"
#include "MathGeoLib\Math\float4x4.h"

class GameObject;

class ComponentTransform : public Component
{
public:
	ComponentTransform(component_type type, float3 pos, float3 scale, Quat rot, GameObject* _parent);
	~ComponentTransform();

	void Update();
	void DeleteComponent();
	float4x4 GetRenderingMatrix();
	void OnProperties();
	void SetPosition(float3 pos);
	void SetScale(float3 scale);
	void SetRotation(float3 rot);
	
	component_type type = c_transform;
	float3 position;
	float3 scalation;
	Quat rotation;
	float4x4 local_mat;
};

#endif // !__COMPONENTTRANSFORM_H__

