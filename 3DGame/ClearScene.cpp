#include "ClearScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"
#include "Game.h"

ClearScene::ClearScene(SceneManager& mgr) : Scene(mgr),
//������
m_bgHandle(-1),
m_rogoHandle(-1)
{
	//���S�̃n���h��
	m_rogoHandle = LoadGraph("data/image/GameClear.png");
}

ClearScene::~ClearScene()
{
	//�������̊J��
	DeleteGraph(m_rogoHandle);
}

void ClearScene::Init()
{
}

void ClearScene::Update(Input& input)
{
	//Enter�������ꂽ�Ƃ�
	if (input.IsTriggered("OK"))
	{
		//���̃V�[���Ɉړ�����
		manager_.ChangeScene(std::make_shared<TitleScene>(manager_));
	}
}

void ClearScene::Draw()
{
	//�`��
	DrawGraph(Game::kScreenWidth / 8, 0, m_rogoHandle, true);
}
