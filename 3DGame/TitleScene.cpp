#include "TitleScene.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "Input.h"

TitleScene::TitleScene(SceneManager& mgr) : Scene(mgr),
m_frame(60)
{
	updateFunc_ = &TitleScene::FadeInUpdate;
	drawFunc_ = &TitleScene::FadeDraw;

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
	(this->*updateFunc_)(input);
}

void TitleScene::Draw()
{
	(this->*drawFunc_)();
}

void TitleScene::FadeInUpdate(Input& input)
{
	m_frame--;
	if (m_frame <= 0)
	{
		//遷移条件
		updateFunc_ = &TitleScene::NormalUpdate;
		drawFunc_ = &TitleScene::NormalDraw;
	}
}

void TitleScene::NormalUpdate(Input& input)
{
	//Enterが押されたとき
	if (input.IsTriggered("OK"))
	{
		//FadeUpdateとFadeDrawを呼ぶ
		updateFunc_ = &TitleScene::FadeOutUpdate;
		drawFunc_ = &TitleScene::FadeDraw;
	}
}

void TitleScene::FadeOutUpdate(Input& input)
{
	m_frame++;
	if (m_frame >= 60) {
		//次のシーンに移動する
		manager_.ChangeScene(std::make_shared<SceneMain>(manager_));
	}
}

void TitleScene::FadeDraw()
{
	//フェード暗幕
	int alpha = 255 * (float)m_frame / 60.0f;
	SetDrawBlendMode(DX_BLENDMODE_MULA, alpha);
	DrawBox(0, 0, 1080, 720, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleScene::NormalDraw()
{
	DrawGraph(0,0,m_handle,true);
}
