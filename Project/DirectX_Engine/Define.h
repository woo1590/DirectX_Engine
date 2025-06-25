#pragma once

enum class ObjectType
{
	Player,
	Enemy,
	Bullet,
	Count
};

enum KEY
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SPACE,
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
	LSHIFT, RSHIFT,
	LCTRL, RCTRL,
	TAB,
	ESC,
	LBUTTON,
	RBUTTON,
	KEY_END
};

enum KEY_STATE
{
	KS_NONE,
	KEY_PRESS,
	KEY_DOWN,
	KEY_RELEASE
};

typedef struct tagKeyInfo
{
	KEY_STATE	eKeyState = KS_NONE;
	bool		bPrePress = false;
}KEYINFO;