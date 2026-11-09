#include "Projectile.h"
#include "App.h"

Projectile::Projectile(VEC2 dir, float speed)
	: m_Direction(dir)
{
	m_MoveSpeed = speed;
}

int Projectile::Init()
{
	m_Animator.Init("resource/texture/Arrow.png", 3, 15);
	m_Transform.scale = { 3, 3 };
	m_Collider        = { -5, -5, 5, 5 };
	m_Damage          = 30;

	m_Flipbooks.push_back(Animation{ 0, 1, 1 });

	m_Animator.SetAnimation(m_Flipbooks[0]);

	return 0;
}

int Projectile::Update()
{
	long long deltaTime = g_pApp->GetDeltaTime();

	Move(m_Direction, deltaTime);
	m_Animator.Update(deltaTime);
	
	return 0;
}

int Projectile::Render(const VEC2& viewOffset)
{
	m_Animator.Render(m_Transform, viewOffset);

	return 0;
}

void Projectile::Attack(Character* other)
{
	other->TakeDamage(m_Damage);
}