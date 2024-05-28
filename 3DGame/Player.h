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
	//3D���f���̃n���h��
	int m_modelHandle;

	//Player�̍��W
	VECTOR m_pos;

	//�����蔻��p�̋�`
	Rect m_colRect;

	//�����蔻��̉~�̔��a
	float m_radius;
};

