#pragma once
#include "DxLib.h"
#include "Rect.h"
class EnemyBase
{
public:
	EnemyBase(int ModelHandle, VECTOR pos);
	virtual ~EnemyBase();

	void Init();
	virtual void Update() abstract;
	void Draw();

	//座標の設定
	void SetPos(VECTOR mpos) { m_pos = mpos; }
	//プレイヤーの当たり判定を取得する
	Rect GetColRect() const { return m_colRecto; }

protected:

	//モデルのハンドル
	int m_handle;

	//座標
	VECTOR	 m_pos;

	//当たり判定
	Rect m_colRecto;
};


