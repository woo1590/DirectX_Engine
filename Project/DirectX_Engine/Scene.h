#pragma once
class ObjectManager;
class Scene
{
protected:
	ObjectManager* ObjectMgr;
public:
	Scene() = default;
	~Scene(){}

	virtual void Load()PURE;
	virtual void Update(double dt)PURE;
	virtual void Late_Update(double dt)PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Unload()PURE;
};

