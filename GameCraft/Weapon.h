#pragma once

#include "GameObject.h"

class Weapon : public GameObject
{
public:
	Weapon(const Transform& pivot);

	int Init() override;
	void Destroy() override;
	int Update() override;
	int Render() override;

protected:
	int m_txWeapon{ -1 };

	const Transform& m_Pivot;
};

