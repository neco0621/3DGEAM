#pragma once
#include "Scene.h"
#include "Collision.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
class SoccerBall;
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
	std::shared_ptr<Collision> m_pCol;

	std::shared_ptr<DataLoader> m_pDataLoader;
	//ゲームオーバーのフラグ
	bool m_gameOverFlag;
	//ゲームクリアのフラグ
	bool m_gameClearFlag;
	//背景のハンドル
	int m_handle;
	//プレイヤーのモデル
	int m_playerHandle;
	//サッカーボールのモデル
	int m_ballHandle;
	//地面のモデル
	int m_groundModel;
	//経過時間
	float m_timer;
};

