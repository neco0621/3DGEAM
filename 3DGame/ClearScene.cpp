#include "ClearScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"
#include "Game.h"

ClearScene::ClearScene(SceneManager& mgr) : Scene(mgr),
//初期化
m_bgHandle(-1),
m_rogoHandle(-1)
{
	//ロゴのハンドル
	m_rogoHandle = LoadGraph("data/image/GameClear.png");
}

ClearScene::~ClearScene()
{
	//メモリの開放
	DeleteGraph(m_rogoHandle);
}

void ClearScene::Init()
{
}

void ClearScene::Update(Input& input)
{
	//Enterが押されたとき
	if (input.IsTriggered("OK"))
	{
		//次のシーンに移動する
		manager_.ChangeScene(std::make_shared<TitleScene>(manager_));
	}
}

void ClearScene::Draw()
{
	//描画
	DrawGraph(Game::kScreenWidth / 8, 0, m_rogoHandle, true);
}
