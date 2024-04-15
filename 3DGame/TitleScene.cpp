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

void TitleScene::FadeInUpdate(Input& input)
{
	frame_--;
	if (frame_ <= 0) {//遷移条件
		updateFunc_ = &TitleScene::NormalUpdate;
		drawFunc_ = &TitleScene::NormalDraw;
	}
}

void TitleScene::NormalUpdate(Input& input)
{
	//Enterが押されたとき
	if (input.IsTriggered("OK"))
	{
		//FadeUpdateとFadeDrawを呼ぶ
		updateFunc_ = &TitleScene::FadeOutUpdate;
		drawFunc_ = &TitleScene::FadeDraw;
	}
}

void TitleScene::FadeOutUpdate(Input& input)
{
	frame_++;
	if (frame_ >= 60) {
		//次のシーンに移動する
		manager_.ChangeScene(std::make_shared<GamePlayingScene>(manager_));
	}
}

void TitleScene::FadeDraw()
{
	//フェード暗幕
	int alpha = 255 * (float)frame_ / 60.0f;
	SetDrawBlendMode(DX_BLENDMODE_MULA, alpha);
	DrawBox(0, 0, 1280, 720, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleScene::NormalDraw()
{
	printfDx("TitleScene\n");
	ClearDrawScreen();
}

TitleScene::TitleScene(SceneManager& manager) : Scene(manager),
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
	updateFunc_ = &TitleScene::FadeInUpdate;
	drawFunc_ = &TitleScene::FadeDraw;
}

TitleScene::~TitleScene()
{
	//メモリの開放
}

void TitleScene::Init()
{
}

void TitleScene::Update(Input& input)
{
	(this->*updateFunc_)(input);
}

void TitleScene::Draw()
{
	DrawGraph(m_bgPosX, 0, m_bgHandle, true);
	(this->*drawFunc_)();
}