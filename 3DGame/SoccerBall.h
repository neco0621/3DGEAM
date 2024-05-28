#pragma once
#include "DxLib.h"
#include "Rect.h"

class SoccerBall
{
public:
	SoccerBall();
	~SoccerBall();

	void Init();
	void Update();
	void Draw();

	VECTOR GetPos() const { return m_pos; }
	float GetRadius() const { return m_radius; }
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
	VECTOR m_rotation;
	float m_rotatePower;
	float m_maxRotatePower;
	float m_maxTimer;
};

