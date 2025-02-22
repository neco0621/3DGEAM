#include "GameOverScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"

GameOverScene::GameOverScene(SceneManager& mgr) : Scene(mgr),
//初期化
m_handle(-1)
{
	//ロゴのハンドルのロード
	m_rogoHandle = LoadGraph("data/image/GameOver.png");
	//ライトを使うか使わないか
	SetUseLighting(FALSE);
}

GameOverScene::~GameOverScene()
{
	//メモリの開放
	DeleteGraph(m_rogoHandle);
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
		m_manager.ChangeScene(std::make_shared<TitleScene>(m_manager));
	}
}

void GameOverScene::Draw()
{
	//描画
	DrawGraph(0, 0, m_rogoHandle, true);
}
