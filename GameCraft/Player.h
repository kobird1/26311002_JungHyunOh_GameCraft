#pragma once

#include "Character.h"
#include "Weapon.h"
#include <memory>

enum State
{
	IDLE = 0,
	WALK = 4,
	DEAD = 8,
};

enum Direction
{
	FRONT,
	LEFT,
	RIGHT,
	BACK,
};

class Player : public Character
{
public:
	int Init() override;
	int Destroy() override;
	int Update() override;
	int Render(const VEC2& viewOffset) override;

	Weapon* GetWeapon();

protected:
	void Movement(long long deltaTime);
	void Attack(Character* other) override;

protected:
	State					m_State		{ IDLE };
	Direction				m_Direction	{ FRONT };

	int						m_Width		{ 24 };
	int						m_Height	{ 24 };

	std::unique_ptr<Weapon> m_Weapon	{};
	VEC3i					m_MousePos	{};
};

