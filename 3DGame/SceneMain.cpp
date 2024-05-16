#include <DxLib.h>
#include "Input.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "Player.h"
#include "Camera.h"
#include "SoccerBall.h"
#include "Game.h"

SceneMain::SceneMain(SceneManager& manager) : Scene(manager)
{
	m_pPlayer = new Player;
	m_pPlayer->Init();

	m_pCamera = new Camera;
	m_pCamera->Init();

	m_pBall = new SoccerBall;
	m_pBall->Init();
}

SceneMain::~SceneMain()
{
	delete m_pPlayer;
	m_pPlayer = nullptr;

	delete m_pCamera;
	m_pCamera = nullptr;

	delete m_pBall;
	m_pBall = nullptr;
}

void SceneMain::Init()
{
}

void SceneMain::Update(Input& input)
{
	m_pPlayer->Update();
	m_pBall->Update();
	m_pCamera->Update();

	for (int x = 0; x < Game::kScreenWidth; x += 100)
	{
		//‰œ•ûŒü‚Ìü•ª‚ðˆø‚­
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

	//‰¡•ûŒü‚Ìü•ª‚ðˆø‚­
	for (int z = 0; z < Game::kScreenHeight; z += 100)
	{
		VECTOR startPos = VGet(0, 0, z);
		VECTOR endPos = VGet(Game::kScreenWidth, 0, z);
		DrawLine3D(startPos, endPos, 0x0000ff);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);

}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
	m_pCamera->Draw();
	m_pBall->Draw();
}
