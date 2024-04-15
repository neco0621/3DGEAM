#include "ClearScene.h"
#include "DxLib.h"
#include "TitleScene.h"

ClearScene::ClearScene() :
	m_frameCount(0)
{
	m_ClearHandle = LoadGraph("data/Clear.png");
}

ClearScene::~ClearScene()
{
}

void ClearScene::Init()
{
}

std::shared_ptr<SceneBase> ClearScene::Update()
{
	int MouseInput = GetMouseInput();
	if (MouseInput & MOUSE_INPUT_LEFT)
	{
		return std::make_shared<TitleScene>();
	}

	return shared_from_this();
}

void ClearScene::Draw()
{
	DrawString(0, 0, "SceneResult", 0xffffff);
	DrawGraph(0, 0, m_ClearHandle, true);
	DrawString(640,200,"ÉQÅ[ÉÄÉNÉäÉA", 0x00ffff);
}