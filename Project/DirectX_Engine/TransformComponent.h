#pragma once
#include "ObjectComponent.h"
class OrbitComponent;
class TransformComponent :
    public ObjectComponent
{
private:
    math::vec3 Position;
    math::vec3 Scale;
    math::vec3 Rotation;

    math::vec3 Pivot = { 0.f,0.f,0.f };

    TransformComponent* Parent = nullptr;
public:
    TransformComponent(Object* owner);
    ~TransformComponent(){}

    void SetParent(Object* parent);
    void SetParent(TransformComponent* parent) { Parent = parent; }

    void SetPosition(float x, float y, float z) { Position = math::vec3(x, y, z); }
    void SetPosition(math::vec3 pos) { Position = pos; }

    void SetScale(float cx, float cy, float cz) { Scale = math::vec3(cx, cy, cz); }
    void SetScale(math::vec3 scale) { Scale = scale; }

    void SetRotate(math::vec3 rotation);
    void SetRotate(float pitch, float yaw, float roll);

    void SetPivot(math::vec3 pivot) { Pivot = pivot; }
    void SetPivot(float x, float y, float z) { SetPivot(math::vec3(x, y, z)); }

    void Translate(math::vec3 trans);
    void Translate(float x, float y, float z);

    math::vec3 GetPosition()const { return Position; }
    math::vec3 GetScale()const { return Scale; }
    math::vec3 GetRotate()const { return Rotation; }

    math::TransformMatrix GetWorldMatrix()const;
    math::TransformMatrix GetLocalMatrix()const;
};

