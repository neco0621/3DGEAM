#pragma once
#include "Scene.h"
#include "Rect.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
class SoccerBall;
class Bg;
class DataLoader;
class SceneMain : public Scene
{
public:
	SceneMain(SceneManager& mgr);
	virtual ~SceneMain();
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
	//当たり判定
	Rect m_pRect;
	//背景
	Bg* m_pBg;

	DataLoader* m_pDataLoader;
	//ゲームオーバーのフラグ
	bool m_gameOverFlag;

	//背景のハンドル
	int m_handle;

	int m_groundModel;
	//経過時間
	float m_timer;
};

