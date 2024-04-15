#pragma once
#include "Scene.h"

/// <summary>
/// タイトルシーンクラス
/// </summary>
class TitleScene : public Scene
{

public:
	TitleScene(SceneManager& manager);
	~TitleScene();
	void Init();
	void Update(Input& input);
	void Draw();

private:
	//更新メンバ関数ポインタ
	void (TitleScene::* updateFunc_)(Input& input);
	//描画メンバ関数ポインタ
	using DrawFunc_t = void (TitleScene::*) ();
	DrawFunc_t drawFunc_;
	//更新関数
	void FadeInUpdate(Input& input);	//フェードイン状態
	void NormalUpdate(Input& input);	//通常状態
	void FadeOutUpdate(Input& input);	//フェードアウト状態

	//描画関数
	void FadeDraw();	//フェード中描画
	void NormalDraw();	//非フェード描画

	//グラフィックハンドル
	int m_bgHandle;			//背景のハンドル
	int m_titleHandle;		//タイトルのアイコンのハンドル
	int m_shakeHandle;		//画面揺れのハンドル
	int m_titleButton;		//STARTボタンのハンドル
	int frame_;				//フェイドに関するフレーム
	int m_bgPosX;			//背景の描画位置

	//サウンド
	int m_bgm;				//BGM
	int CheckSE;			//STARTボタンを押したときのサウンド

};

