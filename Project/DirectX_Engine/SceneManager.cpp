#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TestScene.h"

void SceneManager::Initialize()
{
	AddScene("Test", new TestScene);

	SetActiveScene("Test");
}

void SceneManager::Update(double dt)
{
	ActiveScene->Update(dt);
}

void SceneManager::Late_Update(double dt)
{
	ActiveScene->Late_Update(dt);
}

void SceneManager::Render(HDC hdc)
{
	ActiveScene->Render(hdc);
}

void SceneManager::Release()
{
}

void SceneManager::SetActiveScene(std::string name)
{
	auto iter = Scenes.find(name);

	if (iter != Scenes.end())
	{
		ActiveScene = iter->second;
		ActiveScene->Load();
	}
}

void SceneManager::AddScene(std::string name, Scene* scene)
{
	Scenes[name] = scene;
}
