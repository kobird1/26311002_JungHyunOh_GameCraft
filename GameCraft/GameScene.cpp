#include "GameScene.h"
#include "glc2d.h"

int GameScene::Init()
{
	m_font1 = g2_FontCreate("±º∏≤√º", 32);
	return 0;
}

int GameScene::Update()
{
	return 0;
}

int GameScene::Render()
{
	g2_FontDrawText(m_font1, { 200, 100 }, 0xFFFF00FF, "æ»≥Á«œººø‰");
	return 0;
}