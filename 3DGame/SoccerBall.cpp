#include "SoccerBall.h"
#include "Game.h"

namespace
{
	constexpr float kRadius				= 100.0f;
	constexpr float kScale				= 100.0f;
	constexpr float kCourveAdjustment	= 150.0f;
	constexpr float kMaxTimer			= 1800.0f;
	constexpr float kMaxCourvePower		= 10.0f;
	constexpr float kPosX				= 540.0f;
	constexpr float kPosZ				= 1500.0f;
}

SoccerBall::SoccerBall() :
	//������
	m_modelHandle(-1),
	m_curvePower(0),
	m_pos(VGet(kPosX, 0.0f, kPosZ)),
	m_radius(kRadius),
	m_speed(15.0f),
	m_timer(1800.0f),
	m_maxTimer(kMaxTimer),
	m_maxCourvePower(10.0f),
	m_scale(kScale),
	m_rotation(VGet(0,0,0)),
	m_rotatePower(0.0f),
	m_courveAdjustment(kCourveAdjustment)
{
	//���f���̃��[�h
	m_modelHandle = MV1LoadModel("data/model/SoccerBall.mv1");
}

SoccerBall::~SoccerBall()
{
	//�������̊J��
	MV1DeleteModel(m_modelHandle);
}

void SoccerBall::Init()
{
	//���f���̑傫���𒲐�
	MV1SetScale(m_modelHandle, VGet(m_scale, m_scale, m_scale));
	//���C�g���g�����g��Ȃ���
	SetUseLighting(FALSE);
}

void SoccerBall::Update()
{
	m_timer--;
	//�c�莞�Ԃɂ���đ�����ς���
	if (m_timer < (m_maxTimer / 3) * 2)
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed * 1.5f));
		m_rotation = VAdd(m_rotation, VGet(0.15f, m_curvePower / m_courveAdjustment, 0));
	}
	else if (m_timer < m_maxTimer / 3)
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed * 2.0f));
		m_rotation = VAdd(m_rotation, VGet(0.2f, m_curvePower / m_courveAdjustment, 0));
	}
	else
	{
		m_pos = VSub(m_pos, VGet(m_curvePower, 0, m_speed));
		m_rotation = VAdd(m_rotation, VGet(0.1f, m_curvePower / m_courveAdjustment, 0));
	}

	//��ʊO�ɍs�����珉���ʒu(X���W�̓����_��)�ɖ߂�
	if (m_pos.z < -300)
	{
		m_pos = VGet(GetRand(720), 0.0f, 2000.0f);

		//�����_���ɓG��I��
		switch (GetRand(2))		//0 or 1 or 2
		{
		case 0:		
			m_curvePower = GetRand(-m_maxCourvePower);
			break;
		case 1:		
			m_curvePower = GetRand(m_maxCourvePower);
			break;
		}
	}

	//��]�p�x��360�ɂȂ�����0�x�ɖ߂�
	if (m_rotation.x > 360)
	{
		m_rotation.x = 0;
	}
	if (m_rotation.y > 360)
	{
		m_rotation.y = 0;
	}

	//���˕Ԃ����Ƃ��ɗ͂𔽓]������
	if (m_pos.x < 0)
	{
		m_curvePower = -m_curvePower;
	}
	if (m_pos.x > Game::kScreenWidth - m_radius)
	{
		m_curvePower = -m_curvePower;
	}

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_modelHandle, m_pos);
	//���f���̊p�x����
	MV1SetRotationXYZ(m_modelHandle, m_rotation);
	//�����蔻��̍X�V
	m_col.SetRadius3D(m_pos.x, m_pos.y, m_pos.z, m_radius);
}

void SoccerBall::Draw()
{
	//���f���̕`��
	MV1DrawModel(m_modelHandle);
#ifdef _DEBUG
	DrawFormatString(80, 120, GetColor(255, 255, 255), "�{�[���̍��W(%.2f,%.5f)", m_pos.x, m_pos.z);
	m_col.DrawBall(GetColor(255, 0, 0), GetColor(255, 0, 0), false);
#endif
}
