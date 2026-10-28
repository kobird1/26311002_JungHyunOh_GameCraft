#include "Player.h"
#include "App.h"
#include "GameInput.h"

int Player::Init()
{
    m_txPlayer = g2_TextureLoad("resource/texture/Player.png");

    return 0;
}

void Player::Destroy()
{

}

int Player::Update()
{
    m_AnimElapsed += g_pApp->GetDeltaTime();
    if (m_AnimElapsed >= m_Flipbook.interval)
    {
        m_AnimElapsed -= m_Flipbook.interval;
        m_AnimIndex = (m_AnimIndex + 1) % m_Flipbook.frameCount;
    }

    const int currFrame = (m_Flipbook.startFrame + m_AnimIndex) * 24;
    src = { currFrame, 0, currFrame + 24, 24 };

    auto keyEvent = GetGameInput()->GetKeyState('A');
    if (EInput::EINPUT_DOWN == keyEvent)
    {
        SetAnimation({ 22, 6, 200 });
    }

    return 0;
}

int Player::Render()
{
    m_Transform.position = { 550, 250 };
    m_Transform.scale    = { 3, 3 };
    g2_Draw2D(m_txPlayer, &src, &m_Transform.position, &m_Transform.scale);

    return 0;
}

void Player::SetAnimation(const Animation& flipbook)
{
    if (flipbook.startFrame < 0 || flipbook.frameCount <= 0 || flipbook.interval <= 0)
    {
        return;
    }

    m_Flipbook    = flipbook;
    m_AnimIndex   = 0;
    m_AnimElapsed = 0;
}