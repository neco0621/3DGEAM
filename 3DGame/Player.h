#pragma once
#include <memory>
#include "DxLib.h"
#include "Collision.h"
#include "DataLoader.h"

class DataLoader;
class Player
{
public:
	Player();
	virtual ~Player();

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

	void SetData(DataLoader::Data inputData);

private:
	//Playerの座標
	VECTOR m_pos;

	//当たり判定用の矩形
	Collision m_col;

	//3Dモデルのハンドル
	int m_modelHandle;

	//3Dモデルのアニメーションインデックス
	int m_attachIndex;
	
	//アニメーションの再生時間
	float m_tottalTime;

	//アニメーションの現在時間
	float m_playTime;

	//当たり判定の円の半径
	float m_radius;

	//移動速度
	float m_speed;

	//大きさ
	float m_scale;

	std::map <std::string, DataLoader::Data> m_data;	//ステージデータ
	std::string m_usedataName;			//使用するステージ名

	std::shared_ptr<DataLoader> m_pDataLoader;

};

