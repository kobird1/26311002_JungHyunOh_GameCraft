#pragma once

#include <vector>
#include "GameTime.h"
#include "GraphicEngine.h"
#include "GameScene.h"

class GameInput;
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
	int  Run();

public:
	void ChangeScene(GAME_PHASE nextScene);

protected:
	GraphicEngine::GAME_WINDOW m_gameWin
	{
		120, 50
		, 1280, 640
		, "GameTitle"
		, true
		, 1.0f
	};
	GraphicEngine m_graphicEngine{};
	GameTime   m_gameTime   {};
	GameInput* m_pGameInput {};

	std::vector<GameScene*> m_sceneList;
	GameScene* m_pGameScene		{};
	bool       m_sceneChanged	{};
	GAME_PHASE m_sceneCurrent	{ SCENE_BEGIN };
	GAME_PHASE m_sceneNext		{};
};

extern App* g_pApp;

