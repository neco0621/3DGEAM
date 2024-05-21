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
	//CSVファイル
	ReadCsv* m_pRead;

	bool m_gameOverFlag;
};

