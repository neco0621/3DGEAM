#pragma once
#include "DxLib.h"
#include "Collision.h"

class SoccerBall
{
public:
	SoccerBall();
	virtual ~SoccerBall();

	void Init();
	void Update();
	void Draw();

	//メンバー変数にアクセスする
	void SetHandle(int handle) { m_modelHandle = handle; }

	//座標の取得
	VECTOR GetPos() const { return m_pos; }
	//半径の取得
	float GetRadius() const { return m_radius; }
	//当たり判定の取得
	Collision GetCol() const { return m_col; }

private:
	//位置情報
	VECTOR m_pos;
	//回転する角度
	VECTOR m_rotation;
	//当たり判定
	Collision m_col;

	//モデルハンドル
	int m_modelHandle;
	//タイマー
	float m_timer;
	//円の半径
	float m_radius;
	//横移動の力
	float m_curvePower;
	//横移動の強さの上限
	float m_maxCourvePower;
	//ボールの速さ
	float m_speed;
	//ボールの大きさ
	float m_scale;
	//カーブの大きさ調整
	float m_courveAdjustment;
	//回転の大きさ
	float m_rotatePower;
	//残り時間
	float m_maxTimer;
	//回転の最大角度
	float m_maxRotation;
};

