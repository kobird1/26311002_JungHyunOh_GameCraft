#pragma once

#include <glc2d.h>

class GameInput
{
public:
	int Init();
	int Update();

public:
	VEC3i MousePosition() const;
	int MouseDelta() const;
	int GetKeyState(KEYCODE keyCode) const;
	int	GetMouseEvent(int nMouse) const;

protected:
};

extern GameInput* GetGameInput();
