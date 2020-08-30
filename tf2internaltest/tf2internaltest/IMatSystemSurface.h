#pragma once
#include "method.h"
#include <cstdint>
#include <Windows.h>
#include <iostream>

class ISurface
{
public:
	void DrawSetColor(int r, int g, int b, int a)
	{
		using DrawSetColor = void(__thiscall*)(void*, int, int, int, int);
		return method<DrawSetColor>(10, this)(this, r, g, b, a);
	}


	void DrawOutlinedRect(int x, int y, int x1, int y1)
	{
		using DrawOutlinedRect = void(__thiscall*)(void*, int, int, int, int);
		return method<DrawOutlinedRect>(14, this)(this, x, y, x1, y1);
	}


};