#pragma once
#include "ObjectComponent.h"
class TransformComponent :
    public ObjectComponent
{
private:
    D3DXVECTOR3 Position;
    D3DXVECTOR3 Scale;
    D3DXVECTOR3 Rotation;

    TransformComponent* Parent = nullptr;
public:
    TransformComponent(Object* owner);
    ~TransformComponent(){}

    void SetParent(Object* parent);
    void SetParent(TransformComponent* parent) { Parent = parent; }

    void SetPosition(float x, float y, float z) { Position = D3DXVECTOR3(x, y, z); }
    void SetPosition(D3DXVECTOR3 pos) { Position = pos; }

    void SetScale(float cx, float cy, float cz) { Scale = D3DXVECTOR3(cx, cy, cz); }
    void SetScale(D3DXVECTOR3 scale) { Scale = scale; }

    void SetRotate(D3DXVECTOR3 rotation);
    void SetRotate(float pitch, float yaw, float roll);

    void Translate(D3DXVECTOR3 trans);
    void Translate(float x, float y, float z);

    D3DXVECTOR3 GetPosition()const { return Position; }
    D3DXVECTOR3 GetScale()const { return Scale; }
    D3DXVECTOR3 GetRotate()const { return Rotation; }

    D3DXMATRIX GetWorldMatrix()const;
};

