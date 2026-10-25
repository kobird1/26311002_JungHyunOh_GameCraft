#include "SceneLobby.h"
#include "GameInput.h"
#include "App.h"

SceneLobby::SceneLobby()
{
	m_message = "Scene Lobby";
}

int SceneLobby::Update()
{
	auto keyEvent = GetGameInput()->GetKeyState(VK_RIGHT);
	if (EInput::EINPUT_DOWN == keyEvent)
	{
		g_pApp->ChangeScene(GAME_PHASE::SCENE_PLAY);
	}

	return 0;
}