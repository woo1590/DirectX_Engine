#include "pch.h"
#include "TestScene.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Gun.h"

//component
#include "TransformComponent.h"
void TestScene::Load()
{
	ObjectMgr = new ObjectManager(this);
	ObjectMgr->Initialize();

	auto player = new Player(ObjectMgr, ObjectType::Player);
	auto gun = new Gun(ObjectMgr, ObjectType::Player);

	auto gunTransform = gun->GetComponent<TransformComponent>();
	gunTransform->SetParent(player);
	gunTransform->SetPosition(0.f, 0.f, 0.f);
	gunTransform->SetPivot(0.f, 0.f, 0.f);

	ObjectMgr->AddObject(ObjectType::Player, player);
	ObjectMgr->AddObject(ObjectType::Player, gun);
}

void TestScene::Update(double dt)
{
	ObjectMgr->Update(dt);
}

void TestScene::Late_Update(double dt)
{
	ObjectMgr->Late_Update(dt);
}

void TestScene::Render(HDC hdc)
{
	ObjectMgr->Render(hdc);
}

void TestScene::Unload()
{
}
