#pragma once
#include "DxLib.h"
#include "Collision.h"

class SoccerBall
{
public:
	SoccerBall();
	virtual ~SoccerBall();

	void Init();
	void Update();
	void Draw();

	//�����o�[�ϐ��ɃA�N�Z�X����
	void SetHandle(int handle) { m_modelHandle = handle; }

	//���W�̎擾
	VECTOR GetPos() const { return m_pos; }
	//���a�̎擾
	float GetRadius() const { return m_radius; }
	//�����蔻��̎擾
	Collision GetCol() const { return m_col; }

private:
	//�ʒu���
	VECTOR m_pos;
	//��]����p�x
	VECTOR m_rotation;
	//�����蔻��
	Collision m_col;

	//���f���n���h��
	int m_modelHandle;
	//�^�C�}�[
	float m_timer;
	//�~�̔��a
	float m_radius;
	//���ړ��̗�
	float m_curvePower;
	//���ړ��̋����̏��
	float m_maxCourvePower;
	//�{�[���̑���
	float m_speed;
	//�{�[���̑傫��
	float m_scale;
	//�J�[�u�̑傫������
	float m_courveAdjustment;
	//��]�̑傫��
	float m_rotatePower;
	//�c�莞��
	float m_maxTimer;
	//��]�̍ő�p�x
	float m_maxRotation;
};

