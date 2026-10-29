#pragma once

#include "Character.h"
#include "Weapon.h"
#include <memory>
#include <vector>

using std::vector;

enum State
{
	IDLE = 0,
	WALK = 4,
};

enum Direction
{
	FRONT,
	LEFT,
	RIGHT,
	BACK,
};

class Player : public Character
{
public:
	int  Init() override;
	void Destroy() override;
	int  Update() override;
	int  Render() override;

	const VEC2 GetCenter(int width, int height);

protected:
	Animator				m_Animator	{};
	vector<Animation>		m_Flipbooks {};
	State					m_State		{ IDLE };
	Direction				m_Direction	{ FRONT };

	int  m_Width  { 24 };
	int  m_Height { 24 };
	VEC2 m_Center {};

	std::unique_ptr<Weapon> m_Weapon {};
};

