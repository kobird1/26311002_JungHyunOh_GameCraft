#pragma once

#include "GameObject.h"
#include "Animator.h"
#include <memory>
#include "Projectile.h"

class Weapon : public GameObject
{
public:
	Weapon(const VEC2& pivot, const VEC3i& mousePos);

	int Init() override;
	int Destroy() override;
	int Update() override;
	int Render(const VEC2& viewOffset) override;

	void Attack();
	std::unique_ptr<Projectile> TakeProjectile();

protected:
	Animator	 m_Animator {};
	int			 m_Width    { 48 };
	int			 m_Height   { 48 };

	const VEC2&	 m_ParentPivot;
	const VEC3i& m_MousePos;

	VEC2 m_AimDirection   {};
	float m_CoolTime      { 2.0f };
	float m_CoolRemaining {};
	bool m_IsAttacking    {};

	std::vector<Animation>      m_Flipbooks;
	std::unique_ptr<Projectile> m_Arrow;
};

