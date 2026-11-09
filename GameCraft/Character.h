#pragma once

#include "GameObject.h"
#include "Animator.h"
#include <vector>

using std::vector;

class Character : public GameObject
{
public:
	void TakeDamage(int damage);
	virtual void Attack(Character* other) = 0;

	void Move(const VEC2& moveDirection, long long deltaTime);
	bool IsAlive() const;
	RECT GetCollider() const;

protected:
	Animator		  m_Animator  {};
	vector<Animation> m_Flipbooks {};

	int  m_Hp	     {};
	int  m_MaxHp	 {};
	int  m_Damage	 {};

	RECT m_Collider  {};

	int  m_MoveSpeed {};
};

