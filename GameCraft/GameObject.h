#pragma once

#include "glc2d.h"

struct Transform
{
	VEC2  position { 0.0f, 0.0f };
	VEC2  scale	   { 1.0f, 1.0f };
	float rotation {};

	VEC2 GetCenter(int width, int height) const;
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