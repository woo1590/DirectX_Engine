#pragma once
#include "Object.h"
class Bullet :
    public Object
{
private:
    math::vec3 LocalPoint[4];
public:
    Bullet(ObjectManager* owner, ObjectType objType);
    ~Bullet(){}

    void Update(double dt)override;
    void Late_Update(double dt)override;
    void Render(HDC hdc)override;
    void Release()override;
};

