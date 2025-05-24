#include "pch.h"
#include "InputManager.h"
#include "Engine.h"

int g_iKey[256] =
{
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,
	VK_SPACE,
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	'0','1','2','3','4','5','6','7','8','9',
	VK_LSHIFT,VK_RSHIFT,
	VK_LCONTROL,VK_RCONTROL,
	VK_TAB,
	VK_ESCAPE,
	VK_LBUTTON,
	VK_RBUTTON,
};

void InputManager::Initialize()
{
	m_vecKey.reserve(static_cast<size_t>(KEY_END));

	for (int i = 0; i < static_cast<int>(KEY_END); ++i)
	{
		m_vecKey.push_back({ KS_NONE,false });
	}

	CursorPos = { 0,0, };
}

void InputManager::Update()
{
	GetCursorPos(&CursorPos);
	ScreenToClient(Engine::GetInstance().GetWindowHandle(), &CursorPos);

	for (int i = 0; i < m_vecKey.size(); ++i)
	{
		if (GetAsyncKeyState(g_iKey[i]) & 0x8000)	//키 누름 감지
		{
			if (m_vecKey[i].bPrePress)	//이전에 누르고 지금도 누름
			{
				m_vecKey[i].eKeyState = KEY_DOWN;
			}
			else						//이전에 누르지 않았지만 지금 누름	
			{
				m_vecKey[i].bPrePress = true;
				m_vecKey[i].eKeyState = KEY_PRESS;
			}
		}
		else
		{
			if (m_vecKey[i].bPrePress)//이전에 눌렀지만 지금은 누르지 않음
			{
				m_vecKey[i].bPrePress = false;
				m_vecKey[i].eKeyState = KEY_RELEASE;
			}
		}
	}
}

KEY_STATE InputManager::getKeyState(KEY _eKey)
{
	return m_vecKey[static_cast<int>(_eKey)].eKeyState;
}

bool InputManager::isKeyPressed(KEY _ekey)
{
	if (m_vecKey[_ekey].eKeyState == KEY_PRESS && Is_KeyWork) return true;

	return false;
}

bool InputManager::isKeyDown(KEY _ekey)
{
	if (m_vecKey[_ekey].eKeyState == KEY_DOWN && Is_KeyWork) return true;

	return false;
}

bool InputManager::isKeyRelease(KEY _ekey)
{
	if (m_vecKey[_ekey].eKeyState == KEY_RELEASE && Is_KeyWork) return true;

	return false;
}

POINT InputManager::GetCursor()
{
	return CursorPos;
}
