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
	transform->SetScale(100.f, 100.f, 0.f);
	transform->SetRotate(0.f, 0.f, 0.f);

	LocalPoint[0] = { -0.5f,-0.5f,0.f };	//플레이어 로컬 좌표
	LocalPoint[1] = { -0.5f,0.5f,0.f };
	LocalPoint[2] = { 0.5f,0.5f,0.f };
	LocalPoint[3] = { 0.5f,-0.5f,0.f };

	GunLocalPoint[0] = { 0.f,0.f,0.f };
	GunLocalPoint[1] = { 1.f,0.f,0.f };
}

void Player::Update(double dt)
{
	auto Input = Engine::GetInstance().GetInputManager();
	auto transform = GetComponent<TransformComponent>();

	if (Input->isKeyDown(RIGHT))
	{
		float angle = transform->GetRotate().z;
		angle -= D3DXToRadian(1.f);

		transform->SetRotate(0.f,0.f,angle);
	}
	if (Input->isKeyDown(LEFT))
	{
		float angle = transform->GetRotate().z;
		angle += D3DXToRadian(1.f);

		transform->SetRotate(0.f, 0.f, angle);
	}
	if (Input->isKeyDown(UP))
	{
		float angle = transform->GetRotate().z;
		D3DXVECTOR3 pos = transform->GetPosition();

		D3DXMATRIX rotMat;
		D3DXMatrixRotationZ(&rotMat, angle);

		D3DXVECTOR3 velocity{ 200.f,0.f,0.f };
		D3DXVec3TransformNormal(&velocity, &velocity, &rotMat);

		transform->Translate(velocity * dt);
	}
	if (Input->isKeyDown(DOWN))
	{
		float angle = transform->GetRotate().z;
		D3DXVECTOR3 pos = transform->GetPosition();

		D3DXMATRIX rotMat;
		D3DXMatrixRotationZ(&rotMat, angle);

		D3DXVECTOR3 velocity{ -200.f,0.f,0.f };
		D3DXVec3TransformNormal(&velocity, &velocity, &rotMat);

		transform->Translate(velocity * dt);
	}
}

void Player::Late_Update(double dt)
{
}

void Player::Render(HDC hdc)
{
	float height = Engine::GetInstance().GetWindowSize().bottom;

	auto transform = GetComponent<TransformComponent>();
	D3DXMATRIX worldMat = transform->GetWorldMatrix();

	D3DXVECTOR3 worldPoint[4]{};
	POINT worldPoint2[4]{};
	
	D3DXVECTOR3 gunWorldPoint[2]{};
	POINT gunWorldPoint2[2]{};

	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3TransformCoord(&worldPoint[i], &LocalPoint[i], &worldMat);
		worldPoint2[i].x = static_cast<LONG>(worldPoint[i].x);
		worldPoint2[i].y = height - static_cast<LONG>(worldPoint[i].y);
	}

	for (int i = 0; i < 2; ++i)
	{
		D3DXVec3TransformCoord(&gunWorldPoint[i], &GunLocalPoint[i], &worldMat);
		gunWorldPoint2[i].x = static_cast<LONG>(gunWorldPoint[i].x);
		gunWorldPoint2[i].y = height - static_cast<LONG>(gunWorldPoint[i].y);
	}

	Polygon(hdc, worldPoint2, 4);
	MoveToEx(hdc, gunWorldPoint2[0].x, gunWorldPoint2[0].y, nullptr);
	LineTo(hdc, gunWorldPoint2[1].x, gunWorldPoint2[1].y);
}

void Player::Release()
{
}
