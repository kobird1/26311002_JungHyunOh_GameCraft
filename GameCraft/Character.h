#pragma once

#include "GameObject.h"

class Character : public GameObject
{
public:
	void TakeDamage(int damage);
	//virtual void Attack(int damage) = 0;

	void Move(int speed);

protected:
	int hp		{};
	int maxHp	{};

	RECT collider{};
};

