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
	std::shared_ptr<Player> m_pPlayer;
	//カメラ
	std::shared_ptr<Camera> m_pCamera;
	//ボール
	std::shared_ptr<SoccerBall> m_pBall;
	//当たり判定
	std::shared_ptr<Rect> m_pRect;
	//背景
	std::shared_ptr<Bg> m_pBg;

	std::shared_ptr<DataLoader> m_pDataLoader;
	//ゲームオーバーのフラグ
	bool m_gameOverFlag;

	bool m_gameClearFlag;
	//背景のハンドル
	int m_handle;

	int m_groundModel;
	//経過時間
	float m_timer;
};

