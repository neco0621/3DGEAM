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

