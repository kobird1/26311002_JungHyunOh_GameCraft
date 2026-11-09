#include "Player.h"
#include "App.h"
#include "GameInput.h"
#include <cmath>

int Player::Init()
{
    m_Animator.Init("resource/texture/Player.png", m_Width, m_Height);
    m_Transform.position = { 550, 250 };
    m_Transform.scale    = { 3, 3 };
    m_Collider           = { -36, -36, 36, 36 };
    m_MoveSpeed          = 120;
    m_MaxHp              = 100;
    m_Hp                 = m_MaxHp;

    m_Flipbooks.push_back(Animation{ 0,  4, 200 });                 //´ë±â + Á¤¸é
    m_Flipbooks.push_back(Animation{ 4,  4, 200 });                 //´ë±â + ¿ÞÂÊ
    m_Flipbooks.push_back(Animation{ 8,  4, 200 });                 //´ë±â + ¿À¸¥ÂÊ
    m_Flipbooks.push_back(Animation{ 12, 4, 200 });                 //´ë±â + µÞ¸é
    m_Flipbooks.push_back(Animation{ 16, 6, 200 });                 //°È±â + Á¤¸é
    m_Flipbooks.push_back(Animation{ 22, 6, 200 });                 //°È±â + ¿ÞÂÊ
    m_Flipbooks.push_back(Animation{ 28, 6, 200 });                 //°È±â + ¿À¸¥ÂÊ
    m_Flipbooks.push_back(Animation{ 34, 6, 200 });                 //°È±â + µÞ¸é
    m_Flipbooks.push_back(Animation{ 40, 4, 200, false });          //»ç¸Á

    m_Animator.SetAnimation(m_Flipbooks[m_State + m_Direction]);

    m_MousePos = GetGameInput()->MousePosition();
    m_Weapon   = std::make_unique<Weapon>(m_Transform.position, m_MousePos);

    return 0;
}

int Player::Destroy()
{
    m_Weapon.reset();
    m_Animator.Destroy();
    m_Flipbooks.clear();

    return 0;
}

int Player::Update()
{
    long long deltaTime = g_pApp->GetDeltaTime();
    
    if (!IsAlive())
    {
        m_State     = State::DEAD;
        m_Direction = Direction::FRONT;

        m_Animator.SetAnimation(m_Flipbooks[m_State + m_Direction]);
        m_Animator.Update(deltaTime);
        return 0;
    }

    Movement(deltaTime);
    
    m_MousePos = GetGameInput()->MousePosition();
    float dx   = m_MousePos.x - g2_GetScnW() * 0.5f;
    float dy   = m_MousePos.y - g2_GetScnH() * 0.5f;

    if (dx != 0.0f || dy != 0.0f)
    {
        if (std::abs(dx) >= std::abs(dy))
            m_Direction = (dx > 0.0f) ? Direction::RIGHT : Direction::LEFT;
        else
            m_Direction = (dy > 0.0f) ? Direction::FRONT : Direction::BACK;
    }

    m_Animator.SetAnimation(m_Flipbooks[m_State + m_Direction]);
    m_Animator.Update(deltaTime);

    if (nullptr != m_Weapon)
    {
        m_Weapon->Update();

        if (State::IDLE == m_State)
            m_Weapon->Attack();
    }

    return 0;
}

int Player::Render(const VEC2& viewOffset)
{
    if (!IsAlive())
    {
        m_Animator.Render(m_Transform, viewOffset);
        return 0;
    }

    if (nullptr != m_Weapon && Direction::BACK == m_Direction)
        m_Weapon->Render(viewOffset);
    
    
    m_Animator.Render(m_Transform, viewOffset);

    if (nullptr != m_Weapon && Direction::BACK != m_Direction)
        m_Weapon->Render(viewOffset);

    return 0;
}

Weapon* Player::GetWeapon()
{
    return m_Weapon.get();
}

void Player::Movement(long long deltaTime)
{
    VEC2 moveDir{ 0.0f, 0.0f };
    auto keyEvent = GetGameInput()->GetKeyState('W');
    if (EInput::EINPUT_PRESS == keyEvent)
        moveDir.y -= 1.0f;

    keyEvent = GetGameInput()->GetKeyState('A');
    if (EInput::EINPUT_PRESS == keyEvent)
        moveDir.x -= 1.0f;

    keyEvent = GetGameInput()->GetKeyState('S');
    if (EInput::EINPUT_PRESS == keyEvent)
        moveDir.y += 1.0f;

    keyEvent = GetGameInput()->GetKeyState('D');
    if (EInput::EINPUT_PRESS == keyEvent)
        moveDir.x += 1.0f;


    if (moveDir.x != 0 || moveDir.y != 0)
        m_State = State::WALK;
    else
        m_State = State::IDLE;

    Move(moveDir, deltaTime);
}

void Player::Attack(Character* other)
{
    if (nullptr == m_Weapon)
        return;

    m_Weapon->Attack();
}
