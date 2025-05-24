#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
    D3DXVECTOR3 LocalPoint[4];
    D3DXVECTOR3 GunLocalPoint[2];
public:
    Player(ObjectManager* owner, ObjectType objType);
    ~Player() { Release(); }

    void Update(double dt)override;
    void Late_Update(double dt)override;
    void Render(HDC hdc)override;
    void Release()override;
};

