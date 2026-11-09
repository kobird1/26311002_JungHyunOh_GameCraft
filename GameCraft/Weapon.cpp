#include "Weapon.h"
#include "App.h"
#include <cmath>

Weapon::Weapon(const VEC2& pivot, const VEC3i& mousePos)
	: m_ParentPivot(pivot)
	, m_MousePos(mousePos)
{
	Init();
}

int Weapon::Init()
{
	m_Animator.Init("resource/texture/Bow.png", m_Width, m_Height);
	m_Flipbooks.push_back(Animation{ 0,  1, 200 });
	m_Flipbooks.push_back(Animation{ 0,  6, 100, false });

	m_Animator.SetAnimation(m_Flipbooks[0]);

	m_Transform.position = m_ParentPivot;
	m_Transform.scale    = { 3, 3 };

	return 0;
}

int Weapon::Destroy()
{
	return 0;
}

int Weapon::Update()
{
	long long deltaTime = g_pApp->GetDeltaTime();
	m_CoolRemaining -= deltaTime * 0.001f;

	float screenCenterX = g2_GetScnW() * 0.5f;
	float screenCenterY = g2_GetScnH() * 0.5f;
	float angle = std::atan2(m_MousePos.y - screenCenterY, m_MousePos.x - screenCenterX);

	m_AimDirection = { std::cos(angle), std::sin(angle) };

	m_Transform.position.x = m_ParentPivot.x + m_AimDirection.x;
	m_Transform.position.y = m_ParentPivot.y + m_AimDirection.y;

	m_Transform.rotation = (angle - 3.14159265f * 0.5f) * -1;

	m_Animator.Update(deltaTime);

	if (m_IsAttacking && m_Animator.IsFinished())
	{
		m_IsAttacking = false;
		m_Animator.SetAnimation(m_Flipbooks[0]);

		auto arrow = std::make_unique<Projectile>(m_AimDirection, 1000.0f);

		if (arrow->Init() < 0)
			return 0;

		arrow->m_Transform.position = m_Transform.position;
		arrow->m_Transform.rotation = m_Transform.rotation;

		m_Arrow = std::move(arrow);
	}

	return 0;
}

int Weapon::Render(const VEC2& viewOffset)
{
	m_Animator.Render(m_Transform, viewOffset);

	return 0;
}

void Weapon::Attack()
{
	if (m_IsAttacking || m_CoolRemaining > 0.0f || m_Arrow)
		return;

	m_IsAttacking = true;
	m_CoolRemaining = m_CoolTime;

	m_Animator.SetAnimation(m_Flipbooks[1]);
}

std::unique_ptr<Projectile> Weapon::TakeProjectile()
{
	return std::move(m_Arrow);
}