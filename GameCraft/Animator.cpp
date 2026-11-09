#include "Animator.h"
#include <cmath>

Animator::~Animator()
{
    Destroy();
}

int Animator::Init(string fileName, int frameWidth, int frameHeight)
{
    m_Texture     = g2_TextureLoad(fileName.c_str());
    m_FrameWidth  = frameWidth;
    m_FrameHeight = frameHeight;

    return 0;
}

int Animator::Destroy()
{
    g2_TextureRelease(m_Texture);

    return 0;
}

int Animator::Update(long long animElapsed)
{
    m_AnimElapsed += animElapsed;
    if (m_AnimElapsed >= m_Flipbook.interval)
    {
        m_AnimElapsed -= m_Flipbook.interval;

        if (m_Flipbook.rooping || m_AnimIndex < m_Flipbook.frameCount - 1)
            m_AnimIndex = (m_AnimIndex + 1) % m_Flipbook.frameCount;
    }

    
    const int left = (m_Flipbook.startFrame + m_AnimIndex) * m_FrameWidth;
    const int top  =  m_Flipbook.row * m_FrameHeight;

    m_Frame = { left, top, left + m_FrameWidth, top + m_FrameHeight };

    return 0;
}

int Animator::Render(const Transform& transform, const VEC2& viewOffset)
{
    VEC2 screenPosition { transform.position.x + viewOffset.x
                        , transform.position.y + viewOffset.y };

    VEC2 center { screenPosition.x - m_FrameWidth  * std::abs(transform.scale.x) * 0.5f
                , screenPosition.y - m_FrameHeight * std::abs(transform.scale.y) * 0.5f };

    g2_Draw2D(m_Texture, &m_Frame, &center, &transform.scale, &screenPosition, transform.rotation);

    return 0;
}

void Animator::SetAnimation(const Animation& flipbook)
{
    if (flipbook.startFrame < 0 || flipbook.frameCount <= 0 || flipbook.interval <= 0)
        return;

    if (m_Flipbook == flipbook)
        return;

    m_Flipbook    = flipbook;
    m_AnimIndex   = 0;
    m_AnimElapsed = 0;
}

bool Animator::IsFinished() const
{
    return m_AnimIndex == m_Flipbook.frameCount - 1;
}

bool Animation::operator==(const Animation& other) const
{
    return startFrame == other.startFrame &&
           frameCount == other.frameCount &&
           interval   == other.interval   &&
           row        == other.row;
}