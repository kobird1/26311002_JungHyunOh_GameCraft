#include "Player.h"
#include "App.h"
#include "GameInput.h"

int Player::Init()
{
    m_Animator.Init("resource/texture/Player.png", m_Width, m_Height);
    m_Transform.position = { 550, 250 };
    m_Transform.scale    = { 3, 3 };
    m_MoveSpeed          = 2;
    m_Center             = GetCenter(m_Width, m_Height);

    m_Flipbooks.push_back(Animation{ 0, 4, 200 });                  //Á¤¸é   + ´ë±â
    m_Flipbooks.push_back(Animation{ 4, 4, 200 });                  //¿ÞÂÊ   + ´ë±â
    m_Flipbooks.push_back(Animation{ 8, 4, 200 });                  //¿À¸¥ÂÊ + ´ë±â
    m_Flipbooks.push_back(Animation{ 12, 4, 200 });                 //µÞ¸é   + ´ë±â
    m_Flipbooks.push_back(Animation{ 16, 6, 200 });                 //Á¤¸é   + °È±â
    m_Flipbooks.push_back(Animation{ 22, 6, 200 });                 //¿ÞÂÊ   + °È±â
    m_Flipbooks.push_back(Animation{ 28, 6, 200 });                 //¿À¸¥ÂÊ + °È±â
    m_Flipbooks.push_back(Animation{ 34, 6, 200 });                 //µÞ¸é   + °È±â

    m_Animator.SetAnimation(m_Flipbooks[m_State + m_Direction]);
    m_Weapon = std::make_unique<Weapon>(m_Center);

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

    Move(moveDir);
    
    VEC3i mousePos = GetGameInput()->MousePosition();

    m_Center = GetCenter(m_Width, m_Height);
    int dx = mousePos.x - m_Center.x;
    int dy = mousePos.y - m_Center.y;

    if (dx != 0.0f || dy != 0.0f)
    {
        if (std::abs(dx) >= std::abs(dy))
            m_Direction = (dx > 0.0f) ? Direction::RIGHT : Direction::LEFT;
        else
            m_Direction = (dy > 0.0f) ? Direction::FRONT : Direction::BACK;
    }


    m_Animator.SetAnimation(m_Flipbooks[m_State + m_Direction]);

    m_Weapon->Update();

    return 0;
}

int Player::Render()
{
    if (Direction::BACK == m_Direction)
        m_Weapon->Render();
    
    m_Animator.Render(m_Transform);

    if(Direction::BACK != m_Direction)
        m_Weapon->Render();

    return 0;
}

const VEC2 Player::GetCenter(int width, int height)
{
    VEC2 center{};
    center.x = m_Transform.position.x + width  * m_Transform.scale.x * 0.5f;
    center.y = m_Transform.position.y + height * m_Transform.scale.y * 0.5f;

    return center;
}