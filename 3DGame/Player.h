#pragma once
#include "DxLib.h"
#include "Rect.h"

class Player
{
public:
	Player();
	~Player();

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
	//3Dモデルのハンドル
	int m_modelHandle;

	//Playerの座標
	VECTOR m_pos;

	//当たり判定用の矩形
	Rect m_colRect;

	//当たり判定の円の半径
	float m_radius;
};

