#pragma once
class Object;
class ObjectComponent
{
protected:
	Object* owner;
public:
	ObjectComponent(Object* owner);
	~ObjectComponent(){}

	virtual void Update(double dt){}
	virtual void Late_Update(double dt){}
	virtual void Render(HDC hdc){}
};

