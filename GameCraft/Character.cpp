#include "Character.h"
#include <cmath>

void Character::TakeDamage(int damage)
{

}

void Character::Move(const VEC2& moveDirection)
{
	float length = std::sqrt(moveDirection.x * moveDirection.x + moveDirection.y * moveDirection.y);

	if (0 == length)
		return;

	float dirX = moveDirection.x / length;
	float dirY = moveDirection.y / length;

	m_Transform.position.x += dirX * m_MoveSpeed;
	m_Transform.position.y += dirY * m_MoveSpeed;
}