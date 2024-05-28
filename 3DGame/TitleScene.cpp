#include "TitleScene.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "Input.h"

TitleScene::TitleScene(SceneManager& mgr) : Scene(mgr),
m_frame(60)
{
	m_handle = LoadGraph("data/Title.png");
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::Update(Input& input)
{
	//Enter‚ª‰Ÿ‚³‚ê‚½‚Æ‚«
	if (input.IsTriggered("OK"))
	{
		//Ÿ‚ÌƒV[ƒ“‚ÉˆÚ“®‚·‚é
		manager_.ChangeScene(std::make_shared<SceneMain>(manager_));
	}
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, m_handle, true);
}