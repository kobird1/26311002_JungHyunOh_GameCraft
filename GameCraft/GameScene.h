#pragma once

#include <string>

using std::string;

enum GAME_PHASE : int
{
	SCENE_BEGIN = 0,
	SCENE_LOBBY,
	SCENE_PLAY,
	SCENE_PLAYRESULT,
};

class GameScene
{
public:
	GameScene();
	virtual ~GameScene() = default;

	virtual int Init();
	virtual int Update();
	virtual int Render();
	virtual int Destroy();

protected:
	int m_font1 {-1};
	string  m_message;
};