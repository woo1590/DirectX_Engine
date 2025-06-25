#include "pch.h"
#include "TransformComponent.h"
#include "OrbitComponent.h"
#include "Object.h"

TransformComponent::TransformComponent(Object* owner)
	:ObjectComponent(owner)
{
}

void TransformComponent::SetParent(Object* parent)
{
	Parent = parent->GetComponent<TransformComponent>();
}

void TransformComponent::SetRotate(math::vec3 rotation)
{
	float rotX = math::NormalizeAngle(rotation.x);
	float rotY = math::NormalizeAngle(rotation.y);
	float rotZ = math::NormalizeAngle(rotation.z);

	Rotation = { rotX,rotY,rotZ };
}

void TransformComponent::SetRotate(float pitch, float yaw, float roll)
{
	SetRotate(math::vec3(pitch, yaw, roll));
}

void TransformComponent::Translate(math::vec3 trans)
{
	Position += trans;
}

void TransformComponent::Translate(float x, float y, float z)
{
	Translate(math::vec3(x, y, z));
}

math::TransformMatrix TransformComponent::GetWorldMatrix() const
{
	math::TransformMatrix localMat = GetLocalMatrix();

	if (Parent)
		localMat = localMat * Parent->GetWorldMatrix();
	localMat = localMat;
	localMat = localMat;
	localMat = localMat;
	localMat = localMat;
	localMat = localMat;
	localMat = localMat;
	localMat = localMat;

	return localMat;
}

math::TransformMatrix TransformComponent::GetLocalMatrix() const
{
	math::TransformMatrix scaleMat;
	math::TransformMatrix rotX, rotY, rotZ;
	math::TransformMatrix transMat;
	math::TransformMatrix localMat;
	math::TransformMatrix pivot;
	math::TransformMatrix undoPivot;

	scaleMat.Scaling(Scale.x, Scale.y, Scale.z);
	rotX.RotationX(Rotation.x);
	rotY.RotationY(Rotation.y);
	rotZ.RotationZ(Rotation.z);
	transMat.Translation(Position.x, Position.y, Position.z);
	undoPivot.Translation(Pivot.x, Pivot.y, Pivot.z);
	pivot.Translation(-Pivot.x, -Pivot.y, -Pivot.z);

	localMat = scaleMat * pivot * rotZ * undoPivot * transMat;

	return localMat;
}