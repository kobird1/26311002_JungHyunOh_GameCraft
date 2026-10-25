#include "ScenePlay.h"
#include "GameInput.h"
#include "App.h"

ScenePlay::ScenePlay()
{
	m_message = "Scene Play";
}

int ScenePlay::Update()
{
	auto keyEvent = GetGameInput()->GetKeyState(VK_RIGHT);
	if (EInput::EINPUT_DOWN == keyEvent)
	{
		g_pApp->ChangeScene(GAME_PHASE::SCENE_PLAYRESULT);
	}

	return 0;
}