#include "ClearScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"

ClearScene::ClearScene(SceneManager& mgr) : Scene(mgr),
//������
m_frame(60),
m_bgHandle(-1),
m_rogoHandle(-1)
{
	//m_rogoHandle = LoadGraph();
}

ClearScene::~ClearScene()
{
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
	DrawGraph(0, 0, m_bgHandle, true);
}
