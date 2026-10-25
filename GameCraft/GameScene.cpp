#include "GameScene.h"
#include "glc2d.h"

GameScene::GameScene()
{
	m_message = "Game Scene";
}

int GameScene::Init()
{
	m_font1 = g2_FontCreate("±¼¸²Ã¼", 32);
	return 0;
}

int GameScene::Update()
{
	return 0;
}

int GameScene::Render()
{
	g2_FontDrawText(m_font1, { 10, 10 }, 0xFFFF00FF, m_message.c_str());
	return 0;
}
int GameScene::Destroy()
{
	return 0;
}