#include <DxLib.h>
#include "Input.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "TitleScene.h"
#include "Player.h"
#include "Camera.h"
#include "SoccerBall.h"
#include "Game.h"
#include "Bg.h"
#include "ClearScene.h"
#include "GameOverScene.h"
#include "Rect.h"

SceneMain::SceneMain(SceneManager& manager) : Scene(manager),
m_gameOverFlag(false),
m_timer(1800.0f),
m_groundModel(-1)
{

	//�v���C���[�̃������̊m��
	m_pPlayer = new Player;
	m_pPlayer->Init();

	//�J�����̃��������m��
	m_pCamera = new Camera;
	m_pCamera->Init();

	//�{�[���̃������̊m��
	m_pBall = new SoccerBall;
	m_pBall->Init();

	//�w�i�̃��f���m��
	m_pBg = new Bg;
	m_pBg->Init();

	m_handle = LoadGraph("data/image/Sunny.png");

	m_groundModel = MV1LoadModel("data/model/Ground.MV1");

	MV1SetScale(m_groundModel, VGet(1.5f, 1, 1.5f));
}

SceneMain::~SceneMain()
{
	//�v���C���[�̃������̊J��
	delete m_pPlayer;
	m_pPlayer = nullptr;

	//�J�����̃������̉��
	delete m_pCamera;
	m_pCamera = nullptr;
	
	//�{�[���̃������̊J��
	delete m_pBall;
	m_pBall = nullptr;

	delete m_pBg;
	m_pBg = nullptr;
}

void SceneMain::Init()
{
}

void SceneMain::Update(Input& input)
{
	m_timer--;
	//�X�V����
	m_pPlayer->Update();
	m_pBall->Update();
	m_pCamera->Update();

	Rect playerRect = m_pPlayer->GetColRect();
	Rect ballRect = m_pBall->GetColRect();

	if (ballRect.SphereCollision(playerRect))
	{
		m_gameOverFlag = true;
	}

	if (m_timer < 0)
	{
		manager_.ChangeScene(std::make_shared<ClearScene>(manager_));
	}

	if (m_gameOverFlag == true)
	{
		manager_.ChangeScene(std::make_shared<GameOverScene>(manager_));
	}
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_groundModel, VGet(Game::kScreenWidth / 2,-200,Game::kScreenHeight));
}

void SceneMain::Draw()
{
	//�`���X�N���[�����N���A����
	ClearDrawScreen();

	//�`�揈��
	DrawGraph(0, 0, m_handle, true);
	MV1DrawModel(m_groundModel);
	m_pPlayer->Draw();
	m_pCamera->Draw();
	m_pBall->Draw();
	SetFontSize(64);
	DrawFormatString(470, 100, GetColor(255, 255, 255), "�c�莞��:(%.2f)", m_timer / 60);
}
