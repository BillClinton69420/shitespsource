#pragma once
#include "method.h"


class IPanel
{
public:
	const char* GetName(unsigned int id)
	{
		using GetName = const char* (__thiscall*)(void*, unsigned int);
		return method<GetName>(36, this)(this, id);
	}

	void SetTopmostPopup(unsigned int id, bool state)
	{
		using ass = void(__thiscall*)(void*, unsigned int, bool);
		return method<ass>(59,this)(this, id, state);
	}

};