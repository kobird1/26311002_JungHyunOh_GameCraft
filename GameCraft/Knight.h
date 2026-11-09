#pragma once

#include "Monster.h"

class Knight : public Monster
{
public:
	Knight(const VEC2& playerPos);

	int Init() override;
	int Destroy() override;
	int Update() override;
	int Render(const VEC2& viewOffset) override;

protected:
	void Attack(Character* other) override;

protected:
	int		  m_Width  { 48 };
	int		  m_Height { 32 };
};