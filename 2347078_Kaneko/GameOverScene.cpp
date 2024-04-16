#include "GameOverScene.h"
#include "DxLib.h"
#include "TitleScene.h"

GameOverScene::GameOverScene() :
	m_frameCount(0)
{
	m_GameOverHandle = LoadGraph("data/GameOver.png");
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Init()
{
}

std::shared_ptr<SceneBase> GameOverScene::Update()
{
	m_frameCount++;
	int MouseInput = GetMouseInput();
	if (MouseInput & MOUSE_INPUT_LEFT)
	{
		return std::make_shared<TitleScene>();
	}

	return shared_from_this();
}

void GameOverScene::Draw()
{
	DrawString(0, 0, "SceneResult", 0xffffff);
	DrawGraph(0, 0, m_GameOverHandle, true);
	DrawString(640, 200, "ÉQÅ[ÉÄÉNÉäÉA", 0x00ffff);
	DrawFormatString(0, 16, 0xffffff, "Frame:%d", m_frameCount);
}