#pragma once

#include "GameObject.h"
#include "Animator.h"

class Character : public GameObject
{
public:
	void TakeDamage(int damage);
	//virtual void Attack() = 0;

	void Move(const VEC2& moveDirection);

protected:
	int m_Hp	{};
	int m_MaxHp	{};
	int m_Damage{};

	RECT m_Collider{};

	int m_MoveSpeed{};
};

