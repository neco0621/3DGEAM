#include<DxLib.h>
#include "Input.h"
#include "Game.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Player.h"
//次のシーンのクラスをインクルードしておく
#include "GamePlayingScene.h"
#include <cassert>



GamePlayingScene::GamePlayingScene(SceneManager& manager) : Scene(manager),
//初期化
frame_(0),
m_bgHandle(-1),
m_bgPosX(0)
{
	m_bgHandle = LoadGraph("data/Bg.png");
	frame_ = 60;
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
	m_pPlayer->Update(input);
}

void GamePlayingScene::Draw()
{
	DrawGraph(m_bgPosX, 0, m_bgHandle, true);
	m_pPlayer->Draw();
}