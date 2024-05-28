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

	VECTOR GetPos() const { return m_pos; }
	float GetRadius() const { return m_radius; }
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

