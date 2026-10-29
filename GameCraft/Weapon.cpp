#include "Weapon.h"

Weapon::Weapon(const Transform& pivot)
	:m_Pivot(pivot)
{
	Init();
}

int Weapon::Init()
{
	m_txWeapon = g2_TextureLoad("resource/texture/Bow.png");
	m_Transform.position = m_Pivot.position;
	m_Transform.scale = { 3, 3 };

	return 0;
}

void Weapon::Destroy()
{

}

int Weapon::Update()
{
	m_Transform.position = m_Pivot.position;

	return 0;
}

int Weapon::Render()
{
	RECT src{ 0, 0, 48, 48 };
	g2_Draw2D(m_txWeapon, &src, &m_Transform.position, &m_Transform.scale);

	return 0;
}
