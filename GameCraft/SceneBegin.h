#pragma once

#include "GameScene.h"
#include "Player.h"

class SceneBegin : public GameScene
{
public:
	SceneBegin();

	int Init() override;
	int Update() override;
	int Render() override;

protected:
	Player player;
};

