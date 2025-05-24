#include "pch.h"
#include "TransformComponent.h"
#include "Object.h"

TransformComponent::TransformComponent(Object* owner)
	:ObjectComponent(owner)
{
}

void TransformComponent::SetParent(Object* parent)
{
	Parent = parent->GetComponent<TransformComponent>();
}

void TransformComponent::SetRotate(D3DXVECTOR3 rotation)
{
	float rotX = math::NormalizeAngle(rotation.x);
	float rotY = math::NormalizeAngle(rotation.y);
	float rotZ = math::NormalizeAngle(rotation.z);

	Rotation = { rotX,rotY,rotZ };
}

void TransformComponent::SetRotate(float pitch, float yaw, float roll)
{
	SetRotate(D3DXVECTOR3(pitch, yaw, roll));
}

void TransformComponent::Translate(D3DXVECTOR3 trans)
{
	Position += trans;
}

void TransformComponent::Translate(float x, float y, float z)
{
	Translate(D3DXVECTOR3(x, y, z));
}

D3DXMATRIX TransformComponent::GetWorldMatrix() const
{
	D3DXMATRIX scaleMat; 
	D3DXMATRIX rotX, rotY, rotZ;
	D3DXMATRIX transMat;

	D3DXMatrixScaling(&scaleMat, Scale.x, Scale.y, Scale.z);
	D3DXMatrixRotationX(&rotX, Rotation.x);
	D3DXMatrixRotationY(&rotY, Rotation.y);
	D3DXMatrixRotationZ(&rotZ, Rotation.z);
	D3DXMatrixTranslation(&transMat, Position.x, Position.y, Position.z);

	return (scaleMat * rotZ * rotY * rotX * transMat);
}
