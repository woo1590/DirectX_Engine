#pragma once
class Scene;
class Object;
class ObjectManager
{
private:
	Scene* owner;

	std::vector<std::list<Object*>> Objects;
public:
	ObjectManager(Scene* owner);
	~ObjectManager() { Release(); }

	void Initialize();
	void Update(double dt);
	void Late_Update(double dt);
	void Render(HDC hdc);
	void Release();

	void AddObject(ObjectType objType, Object* object) { Objects[static_cast<int>(objType)].push_back(object); }
	std::list<Object*> GetObjectList(ObjectType objType)const { return Objects[static_cast<int>(objType)]; }
	Object* GetFrontObject(ObjectType objType)const { return Objects[static_cast<int>(objType)].front(); }
};

