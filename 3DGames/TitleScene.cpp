#include "TitleScene.h"
#include "SceneGame.h"
#include "ClearScene.h"
#include "DxLib.h"
#include "Game.h"

TitleScene::TitleScene()
{
	m_TitleHandle = LoadGraph("data/Title.png");
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

std::shared_ptr<SceneBase> TitleScene::Update()
{
	//十字キーの上を押したらタイトルに戻る
	int MouseInput = GetMouseInput();
	if (MouseInput & MOUSE_INPUT_LEFT)
	{
		return std::make_shared<SceneGame>();
	}

	return shared_from_this();
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, m_TitleHandle, true);
	DrawString(0, 0, "SceneTitle", 0xffffff);
	SetFontSize(64);
	DrawString((640 / 2) - 100, Game::kScreenHeight * 0.25f, "ジャンプげーむ", 0x00ffff);
}