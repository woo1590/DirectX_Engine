#pragma once
class Scene;
class SceneManager
{
private:
	std::unordered_map<std::string, Scene*> Scenes;
	Scene* ActiveScene;
public:
	SceneManager() = default;
	~SceneManager(){}

	void Initialize();
	void Update(double dt);
	void Late_Update(double dt);
	void Render(HDC hdc);
	void Release();

	void SetActiveScene(std::string name);
	void AddScene(std::string name, Scene* scene);
};

