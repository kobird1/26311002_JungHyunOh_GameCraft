#pragma once

#include "GameObject.h"
#include "Animator.h"

class Weapon : public GameObject
{
public:
	Weapon(const VEC2& pivot, const VEC3i& mousePos);

	int  Init() override;
	void Destroy() override;
	int  Update() override;
	int  Render() override;

protected:
	Animator		m_Animator {};
	int				m_Width    { 48 };
	int				m_Height   { 48 };

	const VEC2&		m_ParentPivot;
	const VEC3i&	m_MousePos;
};

