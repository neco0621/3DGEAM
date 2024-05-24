#pragma once
#include "DxLib.h"
#include "Rect.h"

class CharacterBase
{
public:
	CharacterBase();
	~CharacterBase();

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	/// <summary>
	/// 座標の取得
	/// </summary>
	/// <returns>現在位置</returns>
	VECTOR GetPos() const { return m_pos; }

	/// <summary>
	/// 当たり判定の取得
	/// </summary>
	/// <returns>現在の当たり判定</returns>
	Rect GetColRect()const { return m_colRect; }

	/// <summary>
	/// 当たり判定の半径の取得
	/// </summary>
	/// <returns>現在の半径</returns>
	float GetRadius()const { return m_radius; }


protected:
	//中心位置
	float m_centerX;
	float m_centerY;

	//半径
	float m_radius;

	//表示位置
	VECTOR m_pos;
	//グラフィックのハンドル
	int m_handle;

	//当たり判定
	Rect m_colRect;

	//移動量
	VECTOR m_vec;
};

