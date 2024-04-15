#include "SceneGame.h"
#include "TitleScene.h"
#include "ClearScene.h"
#include "GameOverScene.h"
#include "Player.h"
#include "EnemyBase.h"
#include "EnemyManager.h"
#include "Bee.h"
#include "Slime.h"
#include "Bg.h"
#include "Camera.h"
#include "DxLib.h"

namespace
{
	//Frameの最大値
	constexpr int kMaxFrame = 5400;

	//秒数で見せるため60で割る
	constexpr int kDiv = 60;

	//エネミーの個体数
	constexpr int kEnemyNum = 30;

	//座標のposXの設定
	constexpr int kPosX = 100;

	//座標のposYの設定
	constexpr int kPosY = 50;
}

SceneGame::SceneGame() :
	m_isSceneEnd(false),
	m_beeHandle(-1),
	m_slimeHandle(-1),
	m_frameCount(0),
	m_pos(VGet(0, 0, 0))
{
	m_pPlayer = new Player;
	m_pPlayer->Init();

	m_pBg = new Bg;
	m_pBg->Init();

	m_pCamera = new Camera();
}

SceneGame::~SceneGame()
{
	delete m_pPlayer;
	m_pPlayer = nullptr;
	
	delete m_pBg;
	m_pBg = nullptr;

	delete m_pCamera;
	m_pCamera = nullptr;

	delete m_pEnemyManager;
	m_pEnemyManager = nullptr;
}

void SceneGame::Init()
{
	m_pEnemyManager = new EnemyManager;
	m_pEnemyManager->CreateEnemy();

}

std::shared_ptr<SceneBase> SceneGame::Update()
{
	m_pPlayer->Update();
	m_pCamera->Update(*m_pPlayer);
	m_pEnemyManager->Update();	
	m_pEnemyManager->OnDamege(m_pPlayer);

	HitPlayer();

	m_frameCount++;
	if (m_frameCount >= kMaxFrame)
	{
		//クリアしたので、クリア画面に移行する
		return std::make_shared<ClearScene>();
	}

	if (m_isSceneEnd == true)
	{
		return std::make_shared<GameOverScene>();
	}

	return shared_from_this();
}

void SceneGame::Draw()
{
	m_pBg->Draw();

	m_pPlayer->Draw();
	
	m_pEnemyManager->Draw();
	
	DrawFormatString(0, 16, 0xffffff, "Frame:%d", m_frameCount/kDiv);
}

void SceneGame::HitPlayer()
{
	bool mGameOver = m_pEnemyManager->isGameOver();

	if (mGameOver == true)
	{
		m_isSceneEnd = true;
	}
}