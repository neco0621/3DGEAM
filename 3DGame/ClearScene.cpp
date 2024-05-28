#include "ClearScene.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Input.h"

ClearScene::ClearScene(SceneManager& mgr) : Scene(mgr),
m_frame(60),
m_handle(-1)
{
}

ClearScene::~ClearScene()
{
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
	DrawGraph(0, 0, m_handle, true);
}
