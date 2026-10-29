#include "Weapon.h"

Weapon::Weapon(const VEC2& pivot)
	:m_ParentPivot(pivot)
{
	Init();
}

int Weapon::Init()
{
	m_txWeapon = g2_TextureLoad("resource/texture/Bow.png");
	m_Transform.position = m_ParentPivot;
	m_Transform.scale = { 3, 3 };

	return 0;
}

void Weapon::Destroy()
{

}

int Weapon::Update()
{
	m_Transform.position.x = m_ParentPivot.x - m_Width * m_Transform.scale.x * 0.5f;
	m_Transform.position.y = m_ParentPivot.y - m_Height * m_Transform.scale.y * 0.5f;

	return 0;
}

int Weapon::Render()
{
	RECT src{ 0, 0, m_Width, m_Height };
	g2_Draw2D(m_txWeapon, &src, &m_Transform.position, &m_Transform.scale);

	return 0;
}
