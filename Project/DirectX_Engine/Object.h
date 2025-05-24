#pragma once
class ObjectManager;
class ObjectComponent;
class Object
{
protected:
	ObjectManager* owner;
	ObjectType ObjType;
public:
	Object(ObjectManager* owner, ObjectType objType);
	~Object() { Release(); }

	virtual void Update(double dt);
	virtual void Late_Update(double dt);
	virtual void Render(HDC hdc);
	virtual void Release();

	/*------------Component----------------*/
protected:
	std::vector<ObjectComponent*> Components;
	std::unordered_map<std::type_index, ObjectComponent*> ComponentMap;

public:
	template<typename T>
	T* AddComponent()
	{
		auto comp = new T(this);
		Components.push_back(comp);
		ComponentMap[typeid(T)] = comp;

		return comp;
	}

	template<typename T>
	T* GetComponent()
	{
		auto it = ComponentMap.find(typeid(T));
		if (it != ComponentMap.end()) return static_cast<T*>(it->second);
		return nullptr;
	}

	template<typename T>
	void RemoveComponent()
	{
		auto it = ComponentMap.find(typeid(T));
		if (it != ComponentMap.end())
		{
			ObjectComponent* target = it->second;

			Components.erase(
				std::remove_if(Components.begin(), Components.end(), [target](ObjectComponent* comp)
					{
						return  comp == target;
					}),
				Components.end()
			);
			ComponentMap.erase(it);
		}
	}
};

