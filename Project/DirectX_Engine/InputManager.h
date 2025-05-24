#pragma once
class InputManager
{
private:
	std::vector<KEYINFO> m_vecKey;

	POINT CursorPos;
	bool Is_KeyWork = true;
public:
	void Initialize();
	void Update();

	KEY_STATE getKeyState(KEY _eKey);
	bool isKeyPressed(KEY _ekey);
	bool isKeyDown(KEY _ekey);
	bool isKeyRelease(KEY _ekey);

	POINT GetCursor();

	void SetKeyWork(bool work) { Is_KeyWork = work; }
};