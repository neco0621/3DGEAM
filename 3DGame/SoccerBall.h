#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "CharacterBase.h"

class SoccerBall : public CharacterBase
{
public:
	SoccerBall();
	virtual ~SoccerBall();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw();

private:
	//タイマー
	float m_timer;
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

