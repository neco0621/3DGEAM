#pragma once
#include "DxLib.h"

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	VECTOR GetPos() const { return m_pos; }

private:
	//3Dモデルのハンドル
	int m_modelHandle;

	//Playerの座標
	VECTOR m_pos;
};

