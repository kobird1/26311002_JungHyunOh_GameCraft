#pragma once

#include "Character.h"

struct Animation
{
	int startFrame;
	int frameCount;
	long long interval;
};

class Player : public Character
{
public:
	int Init() override;
	void Destroy() override;
	int Update() override;
	int Render() override;

	void SetAnimation(const Animation& flipbook);
protected:
	int  m_txPlayer	{ -1 };
	RECT src		{};

	long long m_AnimElapsed {};
	int		  m_AnimIndex	{};
	Animation m_Flipbook	{ 0, 4, 200 };
};

