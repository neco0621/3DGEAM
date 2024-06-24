#include "TitleScene.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "Input.h"
#include "Game.h"

TitleScene::TitleScene(SceneManager& mgr) : Scene(mgr),
m_pos(VGet(Game::kScreenWidth / 2 - 300,0,0)),
m_moveFlag(true)
{
	//ハンドルのロード
	m_bgHandle = LoadGraph("data/image/Title.png");
	m_titleRogo = LoadGraph("data/image/TitleRogo.png");
	//ライトを使うか使わないか
	SetUseLighting(FALSE);
}

TitleScene::~TitleScene()
{
	//メモリの開放
	DeleteGraph(m_bgHandle);
	DeleteGraph(m_titleRogo);
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
	
	//上下に動かす
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
	//描画
	DrawGraph(0, 0, m_bgHandle, true);
	DrawGraph(m_pos.x, m_pos.y, m_titleRogo, true);
}