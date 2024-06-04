#include "ClearScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"
#include "Game.h"

ClearScene::ClearScene(SceneManager& mgr) : Scene(mgr),
//‰Šú‰»
m_frame(60),
m_bgHandle(-1),
m_rogoHandle(-1)
{
	m_rogoHandle = LoadGraph("data/image/GameClear.png");
}

ClearScene::~ClearScene()
{
	//ƒƒ‚ƒŠ‚ÌŠJ•ú
	DeleteGraph(m_rogoHandle);
}

void ClearScene::Init()
{
}

void ClearScene::Update(Input& input)
{
	//Enter‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	if (input.IsTriggered("OK"))
	{
		//Ÿ‚ÌƒV[ƒ“‚ÉˆÚ“®‚·‚é
		manager_.ChangeScene(std::make_shared<TitleScene>(manager_));
	}
}

void ClearScene::Draw()
{
	//•`‰æ
	DrawGraph(Game::kScreenWidth / 8, 0, m_rogoHandle, true);
}
