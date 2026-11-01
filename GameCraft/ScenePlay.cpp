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

	m_Player.Init();

	return 0;
}

int ScenePlay::Update()
{
	m_Player.Update();

	auto keyEvent = GetGameInput()->GetKeyState(VK_RIGHT);
	if (EInput::EINPUT_DOWN == keyEvent)
	{
		g_pApp->ChangeScene(GAME_PHASE::SCENE_PLAYRESULT);
	}

	return 0;
}

int ScenePlay::Render()
{
	VEC2 position { -500, -500 };
	VEC2 scale	  { 3, 3 };

	g2_Draw2D(m_TxBG, nullptr, &position, &scale);
	m_Player.Render();

	return 0;
}

int ScenePlay::Destroy()
{
	g2_SoundRelease(m_Bgm);

	return 0;
}