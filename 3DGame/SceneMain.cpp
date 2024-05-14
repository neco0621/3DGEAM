#include <DxLib.h>
#include "Input.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "Player.h"
#include "Camera.h"
#include "SoccerBall.h"

SceneMain::SceneMain(SceneManager& manager) : Scene(manager)
{
	m_pPlayer = new Player;
	m_pPlayer->Init();

	m_pCamera = new Camera;
	m_pCamera->Init();

	m_pBall.resize(BallMax);
	for (int i = 0; i < m_pBall.size(); i++)
	{
		m_pBall[i]->Init();
	}
}

SceneMain::~SceneMain()
{
	delete m_pPlayer;
	m_pPlayer = nullptr;
}

void SceneMain::Init()
{
}

void SceneMain::Update(Input& input)
{
	m_pPlayer->Update();
	for (int i = 0; i < m_pBall.size(); i++)
	{
		m_pBall[i]->Update();
	}
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();

	m_pCamera->Draw();

	for (int i = 0; i < m_pBall.size(); i++)
	{
		m_pBall[i]->Draw();
	}
}
