#include "Animator.h"

int Animator::Init(string fileName, int frameWidth, int frameHeight)
{
    m_Texture     = g2_TextureLoad(fileName.c_str());
    m_FrameWidth  = frameWidth;
    m_FrameHeight = frameHeight;

    return 0;
}

void Animator::Destroy()
{

}

int Animator::Update(long long animElapsed)
{
    m_AnimElapsed += animElapsed;
    if (m_AnimElapsed >= m_Flipbook.interval)
    {
        m_AnimElapsed -= m_Flipbook.interval;
        m_AnimIndex    = (m_AnimIndex + 1) % m_Flipbook.frameCount;
    }

    const int left = (m_Flipbook.startFrame + m_AnimIndex) * m_FrameWidth;
    const int top  =  m_Flipbook.row * m_FrameHeight;

    m_Frame = { left, top, left + m_FrameWidth, top + m_FrameHeight };

    return 0;
}

int Animator::Render(const Transform& transform)
{
    VEC2 center = transform.GetCenter(m_FrameWidth, m_FrameHeight);
    g2_Draw2D(m_Texture, &m_Frame, &center, &transform.scale, &transform.position, transform.rotation);

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

bool Animation::operator==(const Animation& other) const
{
    return startFrame == other.startFrame &&
           frameCount == other.frameCount &&
           interval   == other.interval   &&
           row        == other.row;
}
