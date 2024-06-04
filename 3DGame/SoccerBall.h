#pragma once
#include "DxLib.h"
#include "Rect.h"

class SoccerBall
{
public:
	SoccerBall();
	virtual ~SoccerBall();

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
	//���f���n���h��
	int m_modelHandle;
	//�ʒu���
	VECTOR m_pos;
	//�^�C�}�[
	float m_timer;
	//�����蔻��
	Rect m_colRect;
	//�~�̔��a
	float m_radius;
	//���ړ��̗�
	int m_curvePower;
	//���ړ��̋����̏��
	float m_maxCourvePower;
	//�{�[���̑���
	float m_speed;
	//�{�[���̑傫��
	float m_scale;
	//�J�[�u�̑傫������
	float m_courveAdjustment;
	//��]����p�x
	VECTOR m_rotation;
	//��]�̑傫��
	float m_rotatePower;
	//��]�̑傫���̍ő�l
	float m_maxRotatePower;
	//�c�莞��
	float m_maxTimer;
};

