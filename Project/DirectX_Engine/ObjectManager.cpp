#include "pch.h"
#include "ObjectManager.h"
#include "Object.h"

ObjectManager::ObjectManager(Scene* owner)
{
	this->owner = owner;
}

void ObjectManager::Initialize()
{
	Objects.resize(static_cast<int>(ObjectType::Count));
}

void ObjectManager::Update(double dt)
{
	for (int type = 0; type < static_cast<int>(ObjectType::Count); ++type)
	{
		for (const auto& object : Objects[type])
		{
			object->Update(dt);
		}
	}
}

void ObjectManager::Late_Update(double dt)
{
}

void ObjectManager::Render(HDC hdc)
{
	for (int type = 0; type < static_cast<int>(ObjectType::Count); ++type)
	{
		for (const auto& object : Objects[type])
		{
			object->Render(hdc);
		}
	}
}

void ObjectManager::Release()
{
	for (int type = 0; type < static_cast<int>(ObjectType::Count); ++type)
	{
		for (auto iter = Objects[type].begin(); iter != Objects[type].end();++iter)
		{
			Safe_Del<Object*>(*iter);
		}
		Objects[type].clear();
	}
}
