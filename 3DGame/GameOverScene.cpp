#include "GameOverScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"

GameOverScene::GameOverScene(SceneManager& mgr) : Scene(mgr),
//������
m_frame(60),
m_handle(-1)
{
	m_rogoHandle = LoadGraph("data/image/GameClear.png");
	//���C�g���g�����g��Ȃ���
	SetUseLighting(FALSE);
}

GameOverScene::~GameOverScene()
{
	//�������̊J��
	DeleteGraph(m_rogoHandle);
}

void GameOverScene::Init()
{
}

void GameOverScene::Update(Input& input)
{
	//Enter�������ꂽ�Ƃ�
	if (input.IsTriggered("OK"))
	{
		//���̃V�[���Ɉړ�����
		manager_.ChangeScene(std::make_shared<TitleScene>(manager_));
	}
}

void GameOverScene::Draw()
{
	//�`��
	DrawGraph(0, 0, m_rogoHandle, true);
}
