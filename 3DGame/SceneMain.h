#pragma once
#include "Scene.h"
#include "Rect.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
class Timer;
class SoccerBall;
class Bg;
class ReadCsv;
class SceneMain : public Scene
{
public:
	SceneMain(SceneManager& mgr);
	~SceneMain();
	virtual void Init();
	virtual void Update(Input& input);
	virtual void Draw();

private:

	//更新メンバ関数ポインタ
	void (SceneMain::* updateFunc_)(Input& input);
	//描画メンバ関数ポインタ
	using DrawFunc_t = void(SceneMain::*) ();
	DrawFunc_t drawFunc_;
	//更新関数
	void FadeInUpdate(Input& input);
	void NormalUpdate(Input& input);
	void FadeOutUpdate(Input& input);

	//描画関数
	void FadeDraw();    //フェード中描画
	void NormalDraw();  //非フェード描画
	float m_frame;

	//プレイヤー
	Player* m_pPlayer;
	//カメラ
	Camera* m_pCamera;
	//ボール
	SoccerBall* m_pBall;
	//タイマー
	Timer* m_pTimer;
	//当たり判定
	Rect m_pRect;
	//背景
	Bg* m_pBg;

	bool m_gameOverFlag;

	int m_handle;

	float m_timer;
};

