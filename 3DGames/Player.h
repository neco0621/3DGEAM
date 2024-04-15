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
	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() const { return m_colRecto; }

private:

	//3D���f���̃n���h��
	int m_handle;

	//Player�̍��W
	VECTOR m_pos;

	//�d��
	float m_Gravity;

	//�W�����v��
	float m_JumpPower;

public:
	//�����蔻��p�̋�`
	Rect m_colRecto;
};

