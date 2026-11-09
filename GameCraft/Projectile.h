#pragma once

#include "Character.h"

class Projectile : public Character
{
public:
	Projectile(VEC2 dir, float speed);

	int Init() override;
	int Update() override;
	int Render(const VEC2& viewOffset) override;

	void Attack(Character* other) override;

protected:
	VEC2 m_Direction;
};

