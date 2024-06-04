#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "DataLoader.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();

	//座標の取得
	VECTOR GetPos() const { return m_pos; }

	//半径の取得
	float GetRadius() const { return m_radius; }

	//当たり判定の取得
	Rect GetColRect() const { return m_colRect; }

	void SetData(DataLoader::Data inputData);

private:
	//3Dモデルのハンドル
	int m_modelHandle;

	//Playerの座標
	VECTOR m_pos;

	//当たり判定用の矩形
	Rect m_colRect;

	//当たり判定の円の半径
	float m_radius;

	float m_speed;

	std::map <std::string, DataLoader::Data> m_data;	//ステージデータ
	std::string m_usedataName;			//使用するステージ名

};

