#include <DxLib.h>
#include "Input.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "TitleScene.h"
#include "GameOverScene.h"
#include "Player.h"
#include "Camera.h"
#include "SoccerBall.h"
#include "Game.h"
#include "Timer.h"
#include "Bg.h"
#include "ReadCsv.h"

SceneMain::SceneMain(SceneManager& manager) : Scene(manager),
m_gameOverFlag(false)
{
	updateFunc_ = &SceneMain::FadeInUpdate;
	drawFunc_ = &SceneMain::FadeDraw;

	//プレイヤーのメモリの確保
	m_pPlayer = new Player;
	m_pPlayer->Init();

	//カメラのメモリを確保
	m_pCamera = new Camera;
	m_pCamera->Init();

	//ボールのメモリの確保
	m_pBall = new SoccerBall;
	m_pBall->Init();

	//タイマーのメモリを確保
	m_pTimer = new Timer;
	m_pTimer->Init();

	m_pBg = new Bg;
	m_pBg->Init();

	m_pRead = new ReadCsv;
	m_pRead->Init();
}

SceneMain::~SceneMain()
{
	//プレイヤーのメモリの開放
	delete m_pPlayer;
	m_pPlayer = nullptr;

	//カメラのメモリの解放
	delete m_pCamera;
	m_pCamera = nullptr;
	
	//ボールのメモリの開放
	delete m_pBall;
	m_pBall = nullptr;

	//タイマーのメモリの開放
	delete m_pTimer;
	m_pTimer = nullptr;

	delete m_pBg;
	m_pBg = nullptr;

	delete m_pRead;
	m_pRead = nullptr;
}

void SceneMain::Init()
{
}

void SceneMain::Update(Input& input)
{
	

	
}

void SceneMain::Draw()
{
	//描画処理
	m_pRead->Draw();
	m_pBg->Draw();
	m_pPlayer->Draw();
	m_pCamera->Draw();
	m_pBall->Draw();
	m_pTimer->Draw();
}

void SceneMain::FadeInUpdate(Input& input)
{
	m_frame--;
	if (m_frame <= 0)
	{
		//遷移条件
		updateFunc_ = &SceneMain::NormalUpdate;
		drawFunc_ = &SceneMain::NormalDraw;
	}
}

void SceneMain::NormalUpdate(Input& input)
{
	//Enterが押されたとき
	if (input.IsTriggered("OK"))
	{
		//FadeUpdateとFadeDrawを呼ぶ
		updateFunc_ = &SceneMain::FadeOutUpdate;
		drawFunc_ = &SceneMain::FadeDraw;
	}
}

void SceneMain::FadeOutUpdate(Input& input)
{
	m_frame++;
	if (m_frame >= 60) {
		//次のシーンに移動する
		manager_.ChangeScene(std::make_shared<GameOverScene>(manager_));

		//更新処理
		m_pPlayer->Update();
		m_pBall->Update();
		m_pCamera->Update();
		m_pTimer->Update();

		//球同士の当たり判定
		VECTOR Vec = VSub(m_pPlayer->GetPos(), m_pBall->GetPos());

		if (VSize(Vec) < m_pPlayer->GetRadius() + m_pBall->GetRadius())
		{
			m_gameOverFlag = true;
		}

		for (int x = 0; x < Game::kScreenWidth; x += 100)
		{
			//奥方向の線分を引く
			VECTOR startPos;
			VECTOR endPos;
			startPos.x = x;
			startPos.y = 0.0f;
			startPos.z = 0.0f;

			endPos.x = x;
			endPos.y = 0.0f;
			endPos.z = 720.0f;

			DrawLine3D(startPos, endPos, 0xff0000);
		}

		//横方向の線分を引く
		for (int z = 0; z < Game::kScreenHeight; z += 100)
		{
			VECTOR startPos = VGet(0, 0, z);
			VECTOR endPos = VGet(Game::kScreenWidth, 0, z);
			DrawLine3D(startPos, endPos, 0x0000ff);
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	}
}

void SceneMain::FadeDraw()
{
}

void SceneMain::NormalDraw()
{
}
