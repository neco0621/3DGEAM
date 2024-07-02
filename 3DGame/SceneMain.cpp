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
	//地面のモデルのサイズ
	constexpr float kGroundScale = 1.5f;
	//プレイヤーのモデルのサイズ
	constexpr float kPlsyerScale = 0.5f;

	//画面の位置
	constexpr float kPosX = 470;
	constexpr float kPosY = 100;

	//タイマーの時間を秒に変換する
	constexpr float kChangeTimer = 60;
	
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

	//CSVのロード用のメモリ確保
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
	MV1SetScale(m_groundModel, VGet(kGroundScale, 1, kGroundScale));
	//モデルのサイズを調整
	MV1SetScale(m_playerHandle, VGet(kPlsyerScale, kPlsyerScale, kPlsyerScale));
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

	//ボールとプレイヤーがぶつかったら
	if (ballCollision.SphereCollision(playerCollision))
	{
		m_gameOverFlag = true;
	}

	//時間切れになったら
	if (m_timer < 0)
	{
		m_gameClearFlag = true;
	}

	if (m_gameOverFlag)
	{
		m_manager.ChangeScene(std::make_shared<GameOverScene>(m_manager));
	}
	else if(m_gameClearFlag)
	{
		m_manager.ChangeScene(std::make_shared<ClearScene>(m_manager));
	}
	// ３Dモデルのポジション設定
	MV1SetPosition(m_groundModel, VGet(Game::kScreenWidth / 2, -200, Game::kScreenHeight));
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

	DrawFormatString(kPosX, kPosY, 0xffffff, "残り時間:(%.2f)", m_timer / kChangeTimer);
	DrawLine3D(VGet(0, 0, Game::kScreenHeight), VGet(0, 0, 0), 0xff0000);
	DrawLine3D(VGet(Game::kScreenWidth, 0, Game::kScreenHeight), VGet(Game::kScreenWidth, 0, 0), 0xff0000);
	DrawLine3D(VGet(0, 0, Game::kScreenHeight), VGet(Game::kScreenWidth, 0, Game::kScreenHeight), 0xff0000);
	DrawLine3D(VGet(0, 0, 0), VGet(Game::kScreenWidth, 0, 0), 0xff0000);
}
