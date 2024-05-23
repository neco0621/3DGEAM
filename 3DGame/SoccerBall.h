#pragma once
#include "DxLib.h"
#include "Rect.h"

class SoccerBall
{
public:
	SoccerBall();
	~SoccerBall();

	void Init();
	void Update();
	void Draw();

	VECTOR GetPos() const { return m_pos; }
	float GetRadius() const { return m_radius; }
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
	VECTOR m_rotation;
	float m_rotatePower;
	float m_maxRotatePower;
	float m_maxTimer;
};

