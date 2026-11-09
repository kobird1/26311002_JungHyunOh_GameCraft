#include "Monster.h"
#include "App.h"

Monster::Monster(const VEC2& playerPos)
	: m_PlayerPos(playerPos)
{

}

void Monster::UpdateBehavior(long long deltaTime)
{
	m_AttackCoolRemaining -= deltaTime * 0.001f;

	if (MONSTER_ATTACK == m_State)
	{
		if (m_Animator.IsFinished())
			m_State = MONSTER_IDLE;
		return;
	}

	if (!IsPlayerInAttackRange(m_AttackRange))
	{
		Movement(deltaTime);
		return;
	}

	m_State = MONSTER_IDLE;

	if (m_AttackCoolRemaining <= 0.0f)
	{
		m_AttackCoolRemaining = m_AttackCoolTime;
		m_State = MONSTER_ATTACK;
		Attack(m_Player);
	}
}

void Monster::SetPlayer(Character* player)
{
	m_Player = player;
}

void Monster::Movement(long long deltaTime)
{
	VEC2 moveDir{ m_PlayerPos.x - m_Transform.position.x
				, m_PlayerPos.y - m_Transform.position.y };

	Move(moveDir, deltaTime);
	m_State = MONSTER_WALK;
}

bool Monster::IsPlayerInAttackRange(float range) const
{
	float dx = m_PlayerPos.x - m_Transform.position.x;
	float dy = m_PlayerPos.y - m_Transform.position.y;

	float distanceSquared = dx * dx + dy * dy;

	return distanceSquared < range * range;
}
