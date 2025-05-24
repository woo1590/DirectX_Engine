#pragma once
#include "Scene.h"
class TestScene :
    public Scene
{
public:
    void Load() override;
    void Update(double dt) override;
    void Late_Update(double dt) override;
    void Render(HDC hdc) override;
    void Unload() override;
};

