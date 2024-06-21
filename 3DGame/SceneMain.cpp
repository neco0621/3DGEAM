#include <DxLib.h>
#include <cassert>
#include "Input.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "TitleScene.h"
#include "Player.h"
#include "Camera.h"
#include "SoccerBall.h"
#include "Game.h"
#include "ClearScene.h"
#include "GameOverScene.h"
#include "Collision.h"
#include "DataLoader.h"


namespace
{
	//サッカーボールのモデルのサイズ
	constexpr float kBallScale = 100.0f;
}


SceneMain::SceneMain(SceneManager& manager) : Scene(manager),
m_gameOverFlag(false),
m_gameClearFlag(false),
m_timer(1800.0f),
m_groundModel(-1),
m_playerHandle(-1),
m_ballHandle(-1)
{
	//プレイヤーのメモリの確保
	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->Init();

	//カメラのメモリを確保
	m_pCamera = std::make_shared<Camera>();
	m_pCamera->Init();

	//ボールのメモリの確保
	m_pBall = std::make_shared<SoccerBall>();
	m_pBall->Init();

	m_pDataLoader = std::make_shared<DataLoader>();
	m_pDataLoader->DataLoad();

	//背景の画像のロード
	m_handle = LoadGraph("data/image/Sunny.png");
	assert(m_handle != -1);
	//地面のモデルのロード
	m_groundModel = MV1LoadModel("data/model/Ground.MV1");
	assert(m_groundModel != -1);
	//プレイヤーのモデルのロード
	m_playerHandle = MV1LoadModel("data/model/Character.mv1");
	assert(m_playerHandle != -1);
	//サッカーボールのモデルのロード
	m_ballHandle = MV1LoadModel("data/model/SoccerBall.mv1");
	assert(m_ballHandle != -1);

	//プレイヤーのモデルのセット
	m_pPlayer->SetHandle(m_playerHandle);
	//サッカーボールのモデルのセット
	m_pBall->SetHandle(m_ballHandle);
}

SceneMain::~SceneMain()
{
	//メモリの開放
	MV1DeleteModel(m_groundModel);
	MV1DeleteModel(m_playerHandle);
	MV1DeleteModel(m_ballHandle);
}

void SceneMain::Init()
{
	//地面のモデルのサイズ調整
	MV1SetScale(m_groundModel, VGet(1.5f, 1, 1.5f));
	//モデルのサイズを調整
	MV1SetScale(m_playerHandle, VGet(0.5f, 0.5f, 0.5f));
	//サッカーボールのモデルの大きさを調整
	MV1SetScale(m_ballHandle, VGet(kBallScale, kBallScale, kBallScale));
}

void SceneMain::Update(Input& input)
{
	m_timer--;
	//更新処理
	m_pPlayer->Update();
	m_pBall->Update();
	m_pCamera->Update();

	Collision playerCollision = m_pPlayer->GetCol();
	Collision ballCollision = m_pBall->GetCol();

	if (ballCollision.SphereCollision(playerCollision))
	{
		m_gameOverFlag = true;
	}

	if (m_timer < 0)
	{
		m_gameClearFlag = true;
	}

	if (m_gameOverFlag)
	{
		manager_.ChangeScene(std::make_shared<GameOverScene>(manager_));
	}
	else if(m_gameClearFlag)
	{
		manager_.ChangeScene(std::make_shared<ClearScene>(manager_));
	}
	// ３Dモデルのポジション設定
	MV1SetPosition(m_groundModel, VGet(Game::kScreenWidth / 2,-200,Game::kScreenHeight));
}

void SceneMain::Draw()
{
	//描画先スクリーンをクリアする
	ClearDrawScreen();

	//描画処理
	DrawGraph(0, 0, m_handle, true);
	MV1DrawModel(m_groundModel);
	m_pPlayer->Draw();
	m_pCamera->Draw();
	m_pBall->Draw();
	//SetFontSize(64);
	DrawFormatString(470, 100, GetColor(255, 255, 255), "残り時間:(%.2f)", m_timer / 60);
	DrawLine3D(VGet(0, 0, Game::kScreenHeight), VGet(0, 0, 0), 0xff0000);
	DrawLine3D(VGet(Game::kScreenWidth, 0, Game::kScreenHeight), VGet(Game::kScreenWidth, 0, 0), 0xff0000);
	DrawLine3D(VGet(0, 0, Game::kScreenHeight), VGet(Game::kScreenWidth, 0, Game::kScreenHeight), 0xff0000);
	DrawLine3D(VGet(0, 0, 0), VGet(Game::kScreenWidth, 0, 0), 0xff0000);
}
