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
	//�T�b�J�[�{�[���̃��f���̃T�C�Y
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
	//�v���C���[�̃������̊m��
	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->Init();

	//�J�����̃��������m��
	m_pCamera = std::make_shared<Camera>();
	m_pCamera->Init();

	//�{�[���̃������̊m��
	m_pBall = std::make_shared<SoccerBall>();
	m_pBall->Init();

	m_pDataLoader = std::make_shared<DataLoader>();
	m_pDataLoader->DataLoad();

	//�w�i�̉摜�̃��[�h
	m_handle = LoadGraph("data/image/Sunny.png");
	assert(m_handle != -1);
	//�n�ʂ̃��f���̃��[�h
	m_groundModel = MV1LoadModel("data/model/Ground.MV1");
	assert(m_groundModel != -1);
	//�v���C���[�̃��f���̃��[�h
	m_playerHandle = MV1LoadModel("data/model/Character.mv1");
	assert(m_playerHandle != -1);
	//�T�b�J�[�{�[���̃��f���̃��[�h
	m_ballHandle = MV1LoadModel("data/model/SoccerBall.mv1");
	assert(m_ballHandle != -1);

	//�v���C���[�̃��f���̃Z�b�g
	m_pPlayer->SetHandle(m_playerHandle);
	//�T�b�J�[�{�[���̃��f���̃Z�b�g
	m_pBall->SetHandle(m_ballHandle);
}

SceneMain::~SceneMain()
{
	//�������̊J��
	MV1DeleteModel(m_groundModel);
	MV1DeleteModel(m_playerHandle);
	MV1DeleteModel(m_ballHandle);
}

void SceneMain::Init()
{
	//�n�ʂ̃��f���̃T�C�Y����
	MV1SetScale(m_groundModel, VGet(1.5f, 1, 1.5f));
	//���f���̃T�C�Y�𒲐�
	MV1SetScale(m_playerHandle, VGet(0.5f, 0.5f, 0.5f));
	//�T�b�J�[�{�[���̃��f���̑傫���𒲐�
	MV1SetScale(m_ballHandle, VGet(kBallScale, kBallScale, kBallScale));
}

void SceneMain::Update(Input& input)
{
	m_timer--;
	//�X�V����
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
	//SetFontSize(64);
	DrawFormatString(470, 100, GetColor(255, 255, 255), "�c�莞��:(%.2f)", m_timer / 60);
	DrawLine3D(VGet(0, 0, Game::kScreenHeight), VGet(0, 0, 0), 0xff0000);
	DrawLine3D(VGet(Game::kScreenWidth, 0, Game::kScreenHeight), VGet(Game::kScreenWidth, 0, 0), 0xff0000);
	DrawLine3D(VGet(0, 0, Game::kScreenHeight), VGet(Game::kScreenWidth, 0, Game::kScreenHeight), 0xff0000);
	DrawLine3D(VGet(0, 0, 0), VGet(Game::kScreenWidth, 0, 0), 0xff0000);
}
