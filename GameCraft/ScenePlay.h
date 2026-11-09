#pragma once

#include "GameScene.h"
#include "Player.h"
#include "Camera.h"
#include "Knight.h"
#include "Projectile.h"
#include <memory>
#include <vector>

using std::vector;

class ScenePlay : public GameScene
{
public:
	ScenePlay();

	int Init() override;
	int Update() override;
	int Render() override;
	int Destroy() override;

protected:
	int	   m_TxBG    { -1 };
	int	   m_Bgm     { -1 };
	int	   m_TxEnemy { -1 };

	Camera m_Camera;
	Player m_Player;
	Knight m_Knight { m_Player.m_Transform.position };

	vector<std::unique_ptr<Projectile>> m_Projectiles;
	vector<Monster*>                    m_Monsters;
};