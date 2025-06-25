#include "pch.h"
#include "OrbitComponent.h"

OrbitComponent::OrbitComponent(Object* owner)
    :ObjectComponent(owner)
{
}

math::TransformMatrix OrbitComponent::GetOrbitMatrix() const
{
    math::TransformMatrix rotMat;
    rotMat.RotationZ(angle);

    math::TransformMatrix transMat;
    transMat.Translation(offset.x, offset.y, offset.z);

    return rotMat * transMat;
}
