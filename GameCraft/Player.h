#pragma once

#include "Character.h"
#include "Weapon.h"
#include <memory>

class Player : public Character
{
public:
	int  Init() override;
	void Destroy() override;
	int  Update() override;
	int  Render() override;

protected:
	Animator	m_Animator	  {};
	Animation	m_FIdleFlipbook{ 0, 4, 200 };
	Animation	m_LIdleFlipbook{ 4, 4, 200 };
	Animation	m_RIdleFlipbook{ 8, 4, 200 };
	Animation	m_BIdleFlipbook{ 12, 4, 200 };

	std::unique_ptr<Weapon> m_Weapon{};
};

