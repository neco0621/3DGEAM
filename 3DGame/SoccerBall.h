#pragma once
#include "DxLib.h"
#include "Rect.h"
#include "CharacterBase.h"

class SoccerBall : public CharacterBase
{
public:
	SoccerBall();
	virtual ~SoccerBall();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw();

private:
	//�^�C�}�[
	float m_timer;
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

