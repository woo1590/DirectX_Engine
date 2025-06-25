#include "pch.h"
#include "Gun.h"
#include "Engine.h"
#include "InputManager.h"
#include "Bullet.h"
#include "ObjectManager.h"

//component
#include "TransformComponent.h"
#include "OrbitComponent.h"

Gun::Gun(ObjectManager* owner, ObjectType objType)
	:Object(owner,objType)
{
	auto transform = AddComponent<TransformComponent>();
	//transform->SetPosition(100.f, 0.f, 0.f);
	transform->SetScale(1.f, 3.f, 0.f);
	transform->SetRotate(0.f, 0.f, 0.f);

	LocalPoint[0] = { 0.f,-5.f,0.f };
	LocalPoint[1] = { 0.f,5.f,0.f };
	LocalPoint[2] = { 150.f,5.f,0.f };
	LocalPoint[3] = { 150.f,-5.f,0.f };

	angle = 0.f;
}

void Gun::Update(double dt)
{
	auto Input = Engine::GetInstance().GetInputManager();
	auto transform = GetComponent<TransformComponent>();


	if (Input->isKeyDown(A))
	{
		math::vec3 rotate = transform->GetRotate();
		rotate.z += math::ToRadian(-1.f);

		transform->SetRotate(rotate);
	}
	if (Input->isKeyDown(D))
	{
		math::vec3 rotate = transform->GetRotate();
		rotate.z += math::ToRadian(1.f);

		transform->SetRotate(rotate);
	}
}

void Gun::Late_Update(double dt)
{
}

void Gun::Render(HDC hdc)
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

void Gun::Release()
{
}
