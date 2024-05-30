#include "TitleScene.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "Input.h"
#include "Game.h"

TitleScene::TitleScene(SceneManager& mgr) : Scene(mgr),
m_frame(60)
{
	m_handle = LoadGraph("data/Title.png");
	//ライトを使うか使わないか
	SetUseLighting(FALSE);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::Update(Input& input)
{
	//Enterが押されたとき
	if (input.IsTriggered("OK"))
	{
		//次のシーンに移動する
		manager_.ChangeScene(std::make_shared<SceneMain>(manager_));
	}
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, m_handle, true);
}