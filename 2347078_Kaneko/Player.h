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
	//プレイヤーの当たり判定を取得する
	Rect GetColRect() const { return m_colRecto; }

private:

	//3Dモデルのハンドル
	int m_handle;

	//Playerの座標
	VECTOR m_pos;

	//重力
	float m_Gravity;

	//ジャンプ力
	float m_JumpPower;

public:
	//当たり判定用の矩形
	Rect m_colRecto;
};

