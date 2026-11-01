#pragma once

#include "GameScene.h"
#include "Player.h"

class ScenePlay : public GameScene
{
public:
	ScenePlay();

	int Init() override;
	int Update() override;
	int Render() override;
	int Destroy() override;

protected:
	int	   m_TxBG { -1 };
	int	   m_Bgm  { -1 };

	Player m_Player;
};