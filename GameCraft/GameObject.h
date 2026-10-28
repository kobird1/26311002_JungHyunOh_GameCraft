#pragma once

#include "glc2d.h"

struct Transform
{
	VEC2 position;
	VEC2 scale;
	float rotation;
};

class GameObject
{
public:
	virtual ~GameObject();

	virtual int  Init();
	virtual void Destroy();
	virtual int  Update();
	virtual int  Render();

public:
	Transform m_Transform;
};