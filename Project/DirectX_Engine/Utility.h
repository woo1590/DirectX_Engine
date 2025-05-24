#pragma once

template<typename T>
void Safe_Del(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}