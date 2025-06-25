#include "pch.h"
#include "Bullet.h"
#include "Engine.h"

//component
#include "TransformComponent.h"

Bullet::Bullet(ObjectManager* owner, ObjectType objType)
	:Object(owner,objType)
{
	LocalPoint[0] = { -5.f,-5.f,0.f };
	LocalPoint[1] = { -5.f,5.f,0.f };
	LocalPoint[2] = { 5.f,5.f,0.f };
	LocalPoint[3] = { 5.f,-5.f,0.f };
}

void Bullet::Update(double dt)
{
	auto transform = GetComponent<TransformComponent>();

	math::vec3 rotate = transform->GetRotate();
	math::TransformMatrix rotMat;
	rotMat.RotationZ(rotate.z);

	math::vec3 foward{ 1.f,0.f,0.f };
	math::vec3 velocity = rotMat.TransformDir(foward) * 300.f * dt;
	transform->Translate(velocity);
}

void Bullet::Late_Update(double dt)
{

}

void Bullet::Render(HDC hdc)
{
	float height = Engine::GetInstance().GetWindowSize().bottom;

	auto transform = GetComponent<TransformComponent>();
	math::TransformMatrix worldMat = transform->GetWorldMatrix();

	math::vec3 worldPoint[4]{};
	POINT worldPoint2[4]{};

	for (int i = 0; i < 4; ++i)
	{
		worldPoint[i] = worldMat.TransformPos(LocalPoint[i]);
		worldPoint2[i].x = static_cast<LONG>(worldPoint[i].x);
		worldPoint2[i].y = height - static_cast<LONG>(worldPoint[i].y);
	}

	Polygon(hdc, worldPoint2, 4);
}

void Bullet::Release()
{

}
