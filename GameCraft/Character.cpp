#include "Character.h"
#include <cmath>

void Character::TakeDamage(int damage)
{
	m_Hp -= damage;
	if (m_Hp < 0)
		m_Hp = 0;
}

void Character::Move(const VEC2& moveDirection, long long deltaTime)
{
	float length = std::sqrt(moveDirection.x * moveDirection.x + moveDirection.y * moveDirection.y);

	if (0 == length)
		return;

	float dirX = moveDirection.x / length;
	float dirY = moveDirection.y / length;

	m_Transform.position.x += dirX * m_MoveSpeed * deltaTime * 0.001f;
	m_Transform.position.y += dirY * m_MoveSpeed * deltaTime * 0.001f;
}

bool Character::IsAlive() const
{
	return m_Hp > 0;
}

RECT Character::GetCollider() const
{
	long x = static_cast<LONG>(m_Transform.position.x);
	long y = static_cast<LONG>(m_Transform.position.y);

	RECT collider = { x + m_Collider.left
					, y + m_Collider.top
					, x + m_Collider.right
					, y + m_Collider.bottom};

	return collider;
}