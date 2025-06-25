#pragma once
#include "ObjectComponent.h"
class TransformComponent;
class OrbitComponent :
    public ObjectComponent
{
private:
    float angle = 0.f;
    float speed = 0.f;
    math::vec3 offset{};
public:
    OrbitComponent(Object* owner);
    ~OrbitComponent(){}

    void SetAngle(float angle) { this->angle = angle; }
    float GetAngle()const { return angle; }
    void SetOffset(math::vec3 offset) { this->offset = offset; }
    void SetOffset(float x, float y, float z) { SetOffset(math::vec3(x, y, z)); }
    math::TransformMatrix GetOrbitMatrix()const;
};

