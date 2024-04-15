#include<DxLib.h>
#include "Input.h"
#include "Game.h"
#include "SceneManager.h"
#include "TitleScene.h"
//���̃V�[���̃N���X���C���N���[�h���Ă���
#include "GamePlayingScene.h"
#include <cassert>


TitleScene::TitleScene(SceneManager& manager) : Scene(manager),
//������
frame_(0),
m_bgHandle(-1),
m_titleHandle(-1),
m_bgPosX(0),
m_shakeHandle(-1),
m_bgm(-1),
CheckSE(-1)
{
	frame_ = 60;
	m_bgHandle = LoadGraph("data/Title.png");
}

TitleScene::~TitleScene()
{
	//�������̊J��
}

void TitleScene::Init()
{
}

void TitleScene::Update(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		manager_.ChangeScene(std::make_shared<GamePlayingScene>(manager_));
	}
}

void TitleScene::Draw()
{
	DrawGraph(m_bgPosX, 0, m_bgHandle, true);
}