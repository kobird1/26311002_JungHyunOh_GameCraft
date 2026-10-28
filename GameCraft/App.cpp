#include "App.h"
#include "GameInput.h"
#include "GameScene.h"
#include "SceneBegin.h"
#include "SceneLobby.h"
#include "ScenePlay.h"
#include "ScenePlayResult.h"

App* g_pApp;

App::App()
{
	g_pApp = this;
	m_pGameInput = new GameInput;

	m_sceneList.push_back(new SceneBegin);
	m_sceneList.push_back(new SceneLobby);
	m_sceneList.push_back(new ScenePlay);
	m_sceneList.push_back(new ScenePlayResult);

	m_pGameScene = m_sceneList[m_sceneCurrent];
}

App::~App()
{

}

int App::Init()
{
	// Glc2d 초기화
	if (0 > m_graphicEngine.Init(m_gameWin))
		return -1;
	m_graphicEngine.SetColor(0xFF006699);


	// GameTime 초기화
	m_gameTime.Init();

	// 폰트 파일 로드
	//g2_FontRegisterFile(파일 경로);

	// Input 초기화
	if (m_pGameInput->Init() < 0)
	{
		Destroy();
		return -2;
	}
	// GameScene 초기화
	if (m_pGameScene->Init() < 0)
	{
		Destroy();
		return -3;
	}

	return 0;
}

void App::Destroy()
{
	if (m_pGameInput)
		delete m_pGameInput; m_pGameInput = nullptr;

	if(m_pGameScene)
		delete m_pGameScene; m_pGameScene = nullptr;
}

int App::Update()
{
	if (m_sceneChanged)
	{
		m_pGameScene->Destroy();

		m_sceneChanged = false;
		m_sceneCurrent = m_sceneNext;
		m_pGameScene   = m_sceneList[m_sceneCurrent];

		m_pGameScene->Init();
	}

	m_gameTime.Update();

	if (m_pGameInput->Update() < 0)
	{
		return -1;
	}

	if (m_pGameScene->Update() < 0)
	{
		return -2;
	}

	return 0;
}

int App::Render()
{
	// GameScene 렌더링
	if (m_pGameScene->Render() < 0)
	{
		return -1;
	}

	return 0;
}

int App::Run()
{
	m_graphicEngine.Run();

	this->Destroy();
	return 0;
}

void App::ChangeScene(GAME_PHASE nextScene)
{
	m_sceneChanged = true;
	m_sceneNext = nextScene;
}

long long App::GetDeltaTime() const
{
	return m_gameTime.deltaTime;
}
