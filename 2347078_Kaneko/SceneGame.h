#pragma once
#include <vector>
#include <memory>
#include "SceneBase.h"
#include "DxLib.h"

class EnemyBase;
class EnemyManager;
class Bg;
class Player;
class Camera;
class SceneGame :public SceneBase
{
public:
	SceneGame();
	~SceneGame();

	virtual void Init();
	virtual std::shared_ptr<SceneBase> Update();
	virtual void Draw();

private:

	void HitPlayer();

	Player* m_pPlayer;

	Bg* m_pBg;

	EnemyManager* m_pEnemyManager;

	Camera* m_pCamera;

	//カウント
	int m_frameCount;

	//蜂のモデル
	int m_beeHandle;

	//スライムのモデル
	int m_slimeHandle;

	//座標の設定用
	VECTOR m_pos;

	//ゲームオーバーなのかのフラグ
	bool m_isSceneEnd;
};

