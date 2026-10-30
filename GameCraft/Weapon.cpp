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
	m_Animator.SetAnimation(Animation{ 0, 1, 200 });

	m_Transform.position = m_ParentPivot;
	m_Transform.scale    = { 3, 3 };

	return 0;
}

void Weapon::Destroy()
{

}

int Weapon::Update()
{
	float angle = atan2(m_MousePos.y - m_ParentPivot.y, m_MousePos.x - m_ParentPivot.x);

	m_Transform.position.x = m_ParentPivot.x + cos(angle) * 1;
	m_Transform.position.y = m_ParentPivot.y + sin(angle) * 1;

	m_Transform.rotation = (angle - 3.14159265f * 0.5f) * -1;

	m_Animator.Update(g_pApp->GetDeltaTime());

	return 0;
}

int Weapon::Render()
{
	m_Animator.Render(m_Transform);

	return 0;
}
