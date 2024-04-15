#include<DxLib.h>
#include "Input.h"
#include "Game.h"
#include "SceneManager.h"
#include "TitleScene.h"
//次のシーンのクラスをインクルードしておく
#include "GamePlayingScene.h"
#include <cassert>


namespace
{
}

void GamePlayingScene::FadeInUpdate(Input& input)
{
	frame_--;
	if (frame_ <= 0) {//遷移条件
		updateFunc_ = &GamePlayingScene::NormalUpdate;
		drawFunc_ = &GamePlayingScene::NormalDraw;
	}
}

void GamePlayingScene::NormalUpdate(Input& input)
{
	//Enterが押されたとき
	if (input.IsTriggered("OK"))
	{
		//FadeUpdateとFadeDrawを呼ぶ
		updateFunc_ = &GamePlayingScene::FadeOutUpdate;
		drawFunc_ = &GamePlayingScene::FadeDraw;
	}
}

void GamePlayingScene::FadeOutUpdate(Input& input)
{
	frame_++;
	if (frame_ >= 60) {
		//次のシーンに移動する
		manager_.ChangeScene(std::make_shared<TitleScene>(manager_));
	}
}

void GamePlayingScene::FadeDraw()
{
	//フェード暗幕
	int alpha = 255 * (float)frame_ / 60.0f;
	SetDrawBlendMode(DX_BLENDMODE_MULA, alpha);
	DrawBox(0, 0, 1280, 720, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GamePlayingScene::NormalDraw()
{
	printfDx("GamePlayingScene\n");
	ClearDrawScreen();
}

GamePlayingScene::GamePlayingScene(SceneManager& manager) : Scene(manager),
//初期化
frame_(0),
m_bgHandle(-1),
m_titleHandle(-1),
m_bgPosX(0),
m_shakeHandle(-1),
m_bgm(-1),
CheckSE(-1)
{
	frame_ = 60;
	updateFunc_ = &GamePlayingScene::FadeInUpdate;
	drawFunc_ = &GamePlayingScene::FadeDraw;
}

GamePlayingScene::~GamePlayingScene()
{
	//メモリの開放
}

void GamePlayingScene::Init()
{
}

void GamePlayingScene::Update(Input& input)
{
	(this->*updateFunc_)(input);
}

void GamePlayingScene::Draw()
{
	DrawGraph(m_bgPosX, 0, m_bgHandle, true);
	(this->*drawFunc_)();
}