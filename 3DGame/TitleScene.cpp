#include "TitleScene.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "Input.h"
#include "Game.h"

TitleScene::TitleScene(SceneManager& mgr) : Scene(mgr),
m_pos(VGet(Game::kScreenWidth / 2 - 300,0,0)),
m_moveFlag(true)
{
	//�n���h���̃��[�h
	m_bgHandle = LoadGraph("data/image/Title.png");
	m_titleRogo = LoadGraph("data/image/TitleRogo.png");
	//���C�g���g�����g��Ȃ���
	SetUseLighting(FALSE);
}

TitleScene::~TitleScene()
{
	//�������̊J��
	DeleteGraph(m_bgHandle);
	DeleteGraph(m_titleRogo);
}

void TitleScene::Init()
{
}

void TitleScene::Update(Input& input)
{
	//Enter�������ꂽ�Ƃ�
	if (input.IsTriggered("OK"))
	{
		//���̃V�[���Ɉړ�����
		m_manager.ChangeScene(std::make_shared<SceneMain>(m_manager));
	}


	if (m_pos.y > 10)
	{
		m_moveFlag = false;
	}
	else if (m_pos.y <= 0)
	{
		m_moveFlag = true;
	}
	
	//�㉺�ɓ�����
	if (m_moveFlag == true)
	{
		m_pos = VAdd(m_pos, VGet(0, 0.2f, 0));
	}
	else if (m_moveFlag == false)
	{
		m_pos = VSub(m_pos, VGet(0, 0.2f, 0));
	}
}

void TitleScene::Draw()
{
	//�`��
	DrawGraph(0, 0, m_bgHandle, true);
	DrawGraph(m_pos.x, m_pos.y, m_titleRogo, true);
}