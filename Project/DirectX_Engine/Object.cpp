#include "pch.h"
#include "Object.h"

Object::Object(ObjectManager* owner, ObjectType objType)
{
	this->owner = owner;
	ObjType = objType;
}

void Object::Update(double dt)
{
}

void Object::Late_Update(double dt)
{
}

void Object::Render(HDC hdc)
{
}

void Object::Release()
{
}
