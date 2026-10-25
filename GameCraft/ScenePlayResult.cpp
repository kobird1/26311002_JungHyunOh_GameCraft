#include "ScenePlayResult.h"
#include "GameInput.h"
#include "App.h"

ScenePlayResult::ScenePlayResult()
{
	m_message = "Game Play Result";
}

int ScenePlayResult::Update()
{
	auto keyEvent = GetGameInput()->GetKeyState(VK_RIGHT);
	if (EInput::EINPUT_DOWN == keyEvent)
	{
		g_pApp->ChangeScene(GAME_PHASE::SCENE_LOBBY);
	}

	return 0;
}