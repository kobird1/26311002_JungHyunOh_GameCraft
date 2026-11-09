#pragma once

#include "glc2d.h"
#include <string>
#include "GameObject.h"

using std::string;

struct Animation
{
	int		  startFrame;
	int		  frameCount;
	long long interval;
	bool      rooping { true };
	int		  row     { 0 };

	bool operator==(const Animation& other) const;
};

class Animator
{
public:
	~Animator();

	int Init(string fileName, int frameWidth, int frameHeight);
	int Destroy();
	int Update(long long animElapsed);
	int Render(const Transform& transform, const VEC2& viewOffset);

	void SetAnimation(const Animation& flipbook);
	bool IsFinished() const;

protected:
	int		  m_Texture	    { -1 };
	long long m_AnimElapsed {};
	int		  m_AnimIndex   {};
	Animation m_Flipbook    {};
	RECT	  m_Frame		{};

	int		  m_FrameWidth  {};
	int		  m_FrameHeight {};
};