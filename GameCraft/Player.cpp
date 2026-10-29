#include "Player.h"
#include "App.h"
#include "GameInput.h"

int Player::Init()
{
    m_Animator.Init("resource/texture/Player.png", 24, 24);
    m_Transform.position = { 550, 250 };
    m_Transform.scale    = { 3, 3 };
    m_MoveSpeed          = 2;

    m_Animator.SetAnimation(m_LIdleFlipbook);
    m_Weapon = std::make_unique<Weapon>(m_Transform);

    return 0;
}

void Player::Destroy()
{

}

int Player::Update()
{
    m_Animator.Update(g_pApp->GetDeltaTime());

    VEC2 moveDir{ 0.0f, 0.0f };
    auto keyEvent = GetGameInput()->GetKeyState('W');
    if (EInput::EINPUT_PRESS == keyEvent)
    {
        moveDir.y -= 1.0f;
        //SetAnimation({ 34, 6, 200 });
    }

    keyEvent = GetGameInput()->GetKeyState('A');
    if (EInput::EINPUT_PRESS == keyEvent)
    {
        moveDir.x -= 1.0f;
        //SetAnimation({ 22, 6, 200 });
    }

    keyEvent = GetGameInput()->GetKeyState('S');
    if (EInput::EINPUT_PRESS == keyEvent)
    {
        moveDir.y += 1.0f;
        //SetAnimation({ 16, 6, 200 });
    }

    keyEvent = GetGameInput()->GetKeyState('D');
    if (EInput::EINPUT_PRESS == keyEvent)
    {
        moveDir.x += 1.0f;
        //SetAnimation({ 28, 6, 200 });
    }

    Move(moveDir);
    
    m_Weapon->Update();

    return 0;
}

int Player::Render()
{
    m_Animator.Render(m_Transform);
    m_Weapon->Render();

    return 0;
}
