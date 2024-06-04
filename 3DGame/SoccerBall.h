#pragma once
#include "DxLib.h"
#include "Rect.h"

class SoccerBall
{
public:
	SoccerBall();
	virtual ~SoccerBall();

	void Init();
	void Update();
	void Draw();

	//座標の取得
	VECTOR GetPos() const { return m_pos; }
	//半径の取得
	float GetRadius() const { return m_radius; }
	//当たり判定の取得
	Rect GetColRect() const { return m_colRect; }

private:
	//モデルハンドル
	int m_modelHandle;
	//位置情報
	VECTOR m_pos;
	//タイマー
	float m_timer;
	//当たり判定
	Rect m_colRect;
	//円の半径
	float m_radius;
	//横移動の力
	int m_curvePower;
	//横移動の強さの上限
	float m_maxCourvePower;
	//ボールの速さ
	float m_speed;
	//ボールの大きさ
	float m_scale;
	//カーブの大きさ調整
	float m_courveAdjustment;
	//回転する角度
	VECTOR m_rotation;
	//回転の大きさ
	float m_rotatePower;
	//回転の大きさの最大値
	float m_maxRotatePower;
	//残り時間
	float m_maxTimer;
};

