#pragma once

#include "GameObject.h"

class Weapon : public GameObject
{
public:
	Weapon(const VEC2& pivot);

	int  Init() override;
	void Destroy() override;
	int  Update() override;
	int  Render() override;

protected:
	int  m_txWeapon{ -1 };

	int  m_Width   { 48 };
	int  m_Height  { 48 };

	const VEC2& m_ParentPivot;
};

