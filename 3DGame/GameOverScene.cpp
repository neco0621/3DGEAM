#include "GameOverScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"

GameOverScene::GameOverScene(SceneManager& mgr) : Scene(mgr),
m_frame(60),
m_handle(-1)
{
	//ライトを使うか使わないか
	SetUseLighting(FALSE);
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Init()
{
}

void GameOverScene::Update(Input& input)
{
	//Enterが押されたとき
	if (input.IsTriggered("OK"))
	{
		//次のシーンに移動する
		manager_.ChangeScene(std::make_shared<TitleScene>(manager_));
	}
}

void GameOverScene::Draw()
{
	DrawGraph(0, 0, m_handle, true);
}
