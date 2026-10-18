#pragma once

#include "GameTime.h"
#include "GraphicEngine.h"

class GameInput;  //전방 선언 해도 인클루드 해야하는데 왜함?
class GameScene;

class App
{
public:
	App();
	virtual ~App();

	int  Init();
	void Destroy();
	int  Update();
	int  Render();
	int Run();

protected:
	GraphicEngine::GAME_WINDOW m_gameWin
	{
		120, 50
		, 960, 600
		, "GameTitle"
		, true
		, 1.0f
	};
	GraphicEngine m_graphicEngine{};
	GameTime   m_gameTime   {};
	GameInput* m_pGameInput {};
	GameScene* m_pGameScene {};
};

extern App* g_pApp;

