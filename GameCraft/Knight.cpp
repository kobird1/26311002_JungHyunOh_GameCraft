#include "Knight.h"
#include "App.h"

Knight::Knight(const VEC2& playerPos)
    : Monster(playerPos)
{

}

int Knight::Init()
{
    m_Animator.Init("resource/texture/Knight.png", m_Width, m_Height);
    m_Transform.position = { 650, 100 };
    m_Transform.scale    = { 3, 3 };
    m_Collider           = { -72, -48, 72, 48 };
    m_MoveSpeed          = 80;
    m_Damage             = 40;
    m_MaxHp              = 50;
    m_Hp                 = m_MaxHp;

    m_AttackRange        = 100;
    m_AttackCoolTime     = 1.0f;

    m_Flipbooks.push_back(Animation{ 0, 6, 200 });                  //´ë±â
    m_Flipbooks.push_back(Animation{ 0, 7, 200, true,  1 });        //°È±â
    m_Flipbooks.push_back(Animation{ 0, 6, 100, false, 2 });        //°ø°Ý
    m_Flipbooks.push_back(Animation{ 0, 2, 200, false, 3 });        //¸Â±â
    m_Flipbooks.push_back(Animation{ 0, 6, 200, false, 4 });        //»ç¸Á

    m_Animator.SetAnimation(m_Flipbooks[m_State]);

    return 0;
}

int Knight::Destroy()
{
    return 0;
}

int Knight::Update()
{
    long long deltaTime = g_pApp->GetDeltaTime();

    if (!IsAlive())
    {
        m_State = MONSTER_DEAD;

        m_Animator.SetAnimation(m_Flipbooks[m_State]);
        m_Animator.Update(deltaTime);
        return 0;

    }
    m_Direction = (m_PlayerPos.x > m_Transform.position.x) ? MONSTER_RIGHT : MONSTER_LEFT;

    UpdateBehavior(deltaTime);
    m_Animator.SetAnimation(m_Flipbooks[m_State]);
    m_Animator.Update(deltaTime);

    return 0;
}

int Knight::Render(const VEC2& viewOffset)
{
    if (!IsAlive())
    {
        m_Animator.Render(m_Transform, viewOffset);
        return 0;
    }
    m_Transform.scale.x = (m_Direction == MONSTER_LEFT) ? -3.0f : 3.0f;

    m_Animator.Render(m_Transform, viewOffset);

    return 0;
}

void Knight::Attack(Character* other)
{
    if (nullptr == other)
        return;

    other->TakeDamage(m_Damage);
}