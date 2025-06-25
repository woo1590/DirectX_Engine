#pragma once
#include "Object.h"
class Gun :
    public Object
{
private:
    math::vec3 LocalPoint[4];
    float angle;
public:
    Gun(ObjectManager* owner, ObjectType objType);
    ~Gun(){}

    void Update(double dt)override;
    void Late_Update(double dt)override;
    void Render(HDC hdc)override;
    void Release()override;
};

