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
	//3D���f���̃n���h��
	int m_modelHandle;

	//Player�̍��W
	VECTOR m_pos;
};

