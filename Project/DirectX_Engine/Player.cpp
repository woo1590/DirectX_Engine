#include "pch.h"
#include "Player.h"
#include "Engine.h"
#include "InputManager.h"

//component
#include "TransformComponent.h"

Player::Player(ObjectManager* owner, ObjectType objType)
	:Object(owner,objType)
{
    auto transform = AddComponent<TransformComponent>();
	transform->SetPosition(400.f, 300.f, 0.f);
	transform->SetScale(1.f, 1.f, 0.f);
	transform->SetRotate(0.f, 0.f, 0.f);
	transform->SetPivot(-100.f, 0.f, 0.f);

	LocalPoint[0] = { -50.f,-50.f,0.f };	//플레이어 로컬 좌표
	LocalPoint[1] = { -50.f,50.f,0.f };
	LocalPoint[2] = { 50.f,50.f,0.f };
	LocalPoint[3] = { 50.f,-50.f,0.f };
}

void Player::Update(double dt)
{
	auto Input = Engine::GetInstance().GetInputManager();
	auto transform = GetComponent<TransformComponent>();

	if (Input->isKeyDown(RIGHT))
	{
		math::vec3 rotate = transform->GetRotate();
		rotate.z += math::ToRadian(-1.f);

		transform->SetRotate(rotate);
	}
	if (Input->isKeyDown(LEFT))
	{
		math::vec3 rotate = transform->GetRotate();
		rotate.z += math::ToRadian(1.f);

		transform->SetRotate(rotate);
	}
	if (Input->isKeyDown(UP))
	{
		float speed = 300.f;
		math::vec3 rotate = transform->GetRotate();
		math::TransformMatrix rotMat;
		rotMat.RotationZ(rotate.z);

		math::vec3 foward{ 1.f,0.f,0.f };
		math::vec3 velocity = rotMat.TransformDir(foward) * speed * dt;

		transform->Translate(velocity);
	}
	if (Input->isKeyDown(DOWN))
	{
		float speed = 300.f;
		math::vec3 rotate = transform->GetRotate();
		math::TransformMatrix rotMat;
		rotMat.RotationZ(rotate.z);

		math::vec3 foward{ -1.f,0.f,0.f };
		math::vec3 velocity = rotMat.TransformDir(foward) * speed * dt;

		transform->Translate(velocity);
	}
}

void Player::Late_Update(double dt)
{
}

void Player::Render(HDC hdc)
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

void Player::Release()
{
}
