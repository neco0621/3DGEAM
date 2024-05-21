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

	//�v���C���[�̃������̊m��
	m_pPlayer = new Player;
	m_pPlayer->Init();

	//�J�����̃��������m��
	m_pCamera = new Camera;
	m_pCamera->Init();

	//�{�[���̃������̊m��
	m_pBall = new SoccerBall;
	m_pBall->Init();

	//�^�C�}�[�̃��������m��
	m_pTimer = new Timer;
	m_pTimer->Init();

	m_pBg = new Bg;
	m_pBg->Init();

	m_pRead = new ReadCsv;
	m_pRead->Init();
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

	//�^�C�}�[�̃������̊J��
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
	//�`�揈��
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
		//�J�ڏ���
		updateFunc_ = &SceneMain::NormalUpdate;
		drawFunc_ = &SceneMain::NormalDraw;
	}
}

void SceneMain::NormalUpdate(Input& input)
{
	//Enter�������ꂽ�Ƃ�
	if (input.IsTriggered("OK"))
	{
		//FadeUpdate��FadeDraw���Ă�
		updateFunc_ = &SceneMain::FadeOutUpdate;
		drawFunc_ = &SceneMain::FadeDraw;
	}
}

void SceneMain::FadeOutUpdate(Input& input)
{
	m_frame++;
	if (m_frame >= 60) {
		//���̃V�[���Ɉړ�����
		manager_.ChangeScene(std::make_shared<GameOverScene>(manager_));

		//�X�V����
		m_pPlayer->Update();
		m_pBall->Update();
		m_pCamera->Update();
		m_pTimer->Update();

		//�����m�̓����蔻��
		VECTOR Vec = VSub(m_pPlayer->GetPos(), m_pBall->GetPos());

		if (VSize(Vec) < m_pPlayer->GetRadius() + m_pBall->GetRadius())
		{
			m_gameOverFlag = true;
		}

		for (int x = 0; x < Game::kScreenWidth; x += 100)
		{
			//�������̐���������
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

		//�������̐���������
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
