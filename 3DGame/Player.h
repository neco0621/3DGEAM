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

	//���W�̎擾
	VECTOR GetPos() const { return m_pos; }

	//���a�̎擾
	float GetRadius() const { return m_radius; }

	//�����蔻��̎擾
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

