#include "ScenePlay.h"
#include "GameInput.h"
#include "App.h"

ScenePlay::ScenePlay()
{
	m_message = "Scene Play";
}

int ScenePlay::Init()
{
	m_TxBG = g2_TextureLoad("resource/texture/Stage01.png");
	m_Bgm  = g2_SoundLoad("resource/audio/NormalStageBGM.mp3");
	g2_SoundPlay(m_Bgm, true);

	m_Camera.Init();
	m_Player.Init();
	m_Camera.AddObject(5, &m_Player);

	m_Monsters.push_back(new Knight(m_Player.m_Transform.position));
	for (Monster* monster : m_Monsters)
	{
		monster->Init();
		m_Camera.AddObject(5, monster);
	}

	return 0;
}

int ScenePlay::Update()
{
	m_Player.Update();
	
	if (auto projectile = m_Player.GetWeapon()->TakeProjectile())
	{
		m_Projectiles.push_back(std::move(projectile));
		m_Camera.AddObject(6, m_Projectiles.back().get());
	}

	m_Camera.m_Transform.position = m_Player.m_Transform.position;

	for (Monster* monster : m_Monsters)
		monster->Update();

	for (auto& projectile : m_Projectiles)
		projectile->Update();

	auto keyEvent = GetGameInput()->GetKeyState(VK_RIGHT);
	if (EInput::EINPUT_DOWN == keyEvent)
	{
		g_pApp->ChangeScene(GAME_PHASE::SCENE_PLAYRESULT);
	}

	const RECT playerCollider = m_Player.GetCollider();

	for (int monsterIndex = 0; monsterIndex < static_cast<int>(m_Monsters.size()); ++monsterIndex)
	{
		Monster* monster = m_Monsters[monsterIndex];
		if (!monster->IsAlive())
			continue;

		monster->SetPlayer(nullptr);
		const RECT monsterCollider = monster->GetCollider();
		RECT overlap{};

		if (IntersectRect(&overlap, &playerCollider, &monsterCollider))
			monster->SetPlayer(&m_Player);

		for (int i = 0; i < static_cast<int>(m_Projectiles.size()); ++i)
		{
			auto& projectile = m_Projectiles[i];
			const RECT arrowCollider = projectile->GetCollider();

			if (IntersectRect(&overlap, &arrowCollider, &monsterCollider))
			{
				projectile->Attack(monster);
				m_Camera.RemoveObject(6, projectile.get());
				m_Projectiles.erase(m_Projectiles.begin() + i);
				--i;
			}
		}
	}

	return 0;
}

int ScenePlay::Render()
{
	VEC2 viewOffset = m_Camera.GetViewOffset();

	VEC2 position { -500.0f + viewOffset.x 
				  , -500.0f + viewOffset.y };

	VEC2 scale    { 3.0f, 3.0f };

	g2_Draw2D(m_TxBG, nullptr, &position, &scale);
	m_Camera.Draw();

	return 0;
}

int ScenePlay::Destroy()
{
	g2_TextureRelease(m_TxBG);
	g2_SoundRelease(m_Bgm);

	m_Camera.ClearObjects();
	m_Player.Destroy();
	m_Projectiles.clear();

	for (Monster* monster : m_Monsters)
		delete monster;

	m_Monsters.clear();

	return 0;
}