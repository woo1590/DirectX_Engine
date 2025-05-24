#include "pch.h"
#include "TestScene.h"
#include "ObjectManager.h"
#include "Player.h"

void TestScene::Load()
{
	ObjectMgr = new ObjectManager(this);
	ObjectMgr->Initialize();

	ObjectMgr->AddObject(ObjectType::Player, new Player(ObjectMgr, ObjectType::Player));
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
