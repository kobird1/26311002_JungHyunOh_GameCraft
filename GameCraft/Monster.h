#pragma once

#include "Character.h"

enum MonsterState
{
	MONSTER_IDLE,
	MONSTER_WALK,
	MONSTER_ATTACK,
	MONSTER_HIT,
	MONSTER_DEAD,
};

enum MonsterDirection
{
	MONSTER_LEFT,
	MONSTER_RIGHT,
};

class Monster : public Character
{
public:
	Monster(const VEC2& playerPos);
	~Monster() = default;

	void UpdateBehavior(long long deltaTime);
	void SetPlayer(Character* player);

protected:
	void Movement(long long deltaTime);
	bool IsPlayerInAttackRange(float range) const;

protected:
	MonsterState	    m_State  { MONSTER_IDLE };
	MonsterDirection m_Direction { MONSTER_LEFT };

	const VEC2& m_PlayerPos;
	Character* m_Player;

	float m_AttackRange			{};
	float m_AttackCoolTime		{};
	float m_AttackCoolRemaining {};
};

