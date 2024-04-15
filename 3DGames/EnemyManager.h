#pragma once
#include "DxLib.h"
#include"Rect.h"

class Player;
class EnemyBase;
class EnemyManager
{
public:
	EnemyManager();
	virtual ~EnemyManager();

	void CreateEnemy();			// 敵の生成
	void DestroyEnemy();		// 敵の削除
	
	void Update();
	void Draw();

	//プレイヤーの当たり判定を取得する
	Rect GetColRect() const { return m_colRecto; }
	void OnDamege(Player* mPlayer);
	bool isGameOver() const { return m_GameOver; }
private:
	
	//敵の最大数
	static constexpr int m_enemyMax = 60;

	EnemyBase* m_pEnemyBase[m_enemyMax];

	//座標の設定
	VECTOR m_pos;

	Rect m_colRecto;
	//蜂のモデル
	int m_beeHandle;

	bool m_GameOver;

	//スライムのモデル
	int m_slimeHandle;
};

