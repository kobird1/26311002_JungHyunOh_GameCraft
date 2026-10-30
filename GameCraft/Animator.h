#pragma once

#include "glc2d.h"
#include <string>
#include "GameObject.h"

using std::string;

struct Animation
{
	int			startFrame;
	int			frameCount;
	long long	interval;
	int			row{ 0 };

	bool operator==(const Animation& other) const;
};

class Animator
{
public:
	int  Init(string fileName, int frameWidth, int frameHeight);
	void Destroy();
	int  Update(long long animElapsed);
	int  Render(const Transform& transform);

	void SetAnimation(const Animation& flipbook);

protected:
	int			m_Texture	  { -1 };
	long long	m_AnimElapsed {};
	int			m_AnimIndex   {};
	Animation	m_Flipbook    {};
	RECT		m_Frame		  {};

	int			m_FrameWidth  {};
	int			m_FrameHeight {};
};