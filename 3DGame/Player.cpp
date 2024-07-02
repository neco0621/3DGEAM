//�w�b�_�[�t�@�C���̃C���N���[�h
#include "Player.h"
#include "Game.h"

namespace
{
	//�X�s�[�h
	constexpr float kSpeed	= 7.0f;
	//���a
	constexpr float kRadius = 70.0f;
	//���f���̃T�C�Y
	constexpr float kScale	= 0.5f;
	//�`�悸��̏C��
	constexpr float kDefference = 50;
	//�`��ʒu
	constexpr float kDrawPos = 80;
}

Player::Player() :
	//������
	m_modelHandle(-1),
	m_radius(kRadius),
	m_pos(VGet(540,0,360)),
	m_speed(kSpeed),
	m_scale(kScale),
	m_playTime(0.0f)
{
	m_attachIndex = MV1AttachAnim(m_modelHandle, 11, -1);
	m_tottalTime = MV1GetAttachAnimTotalTime(m_modelHandle,m_attachIndex);
	MV1SetAttachAnimTime(m_modelHandle, m_attachIndex, m_playTime);
	//SetData(m_data[m_usedataName]);
}

Player::~Player()
{
}

void Player::Init()
{
	//���C�g���g�����g��Ȃ���
	SetUseLighting(FALSE);
}

void Player::Update()
{
	m_playTime += 100.0f;
	//�v���C���[�̈ړ�
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (((pad & PAD_INPUT_UP) | (pad & PAD_INPUT_8)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(0, 0, m_speed));
	}

	if (((pad & PAD_INPUT_DOWN) | (pad & PAD_INPUT_5)) != 0)
	{
		m_pos = VSub(m_pos, VGet(0, 0, m_speed));
	}

	if (((pad & PAD_INPUT_LEFT) | (pad & PAD_INPUT_4)) != 0)
	{
		m_pos = VSub(m_pos, VGet(m_speed, 0, 0));
	}

	if (((pad & PAD_INPUT_RIGHT) | (pad & PAD_INPUT_6)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(m_speed, 0, 0));
	}


	//�v���C���[����ʊO�ɍs���Ȃ��悤�ɍ��W��ݒ�
	if (m_pos.x > Game::kScreenWidth - m_radius)
	{
		m_pos = VGet(Game::kScreenWidth - m_radius, m_pos.y, m_pos.z);
	}
	if (m_pos.x < 0 + m_radius)
	{
		m_pos = VGet(0 + m_radius, m_pos.y, m_pos.z);
	}
	if (m_pos.z > Game::kScreenHeight - m_radius)
	{
		m_pos = VGet(m_pos.x, m_pos.y, Game::kScreenHeight - m_radius);
	}
	if (m_pos.z < 0 + m_radius)
	{
		m_pos = VGet(m_pos.x, m_pos.y, 0 + m_radius);
	}

	// �A�j���[�V�����Đ����Ԃ��A�j���[�V�����̑����Ԃ��z���Ă����烋�[�v������
	if (m_playTime >= m_tottalTime)
	{
		// �V�����A�j���[�V�����Đ����Ԃ́A�A�j���[�V�����Đ����Ԃ���A�j���[�V���������Ԃ�����������
		m_playTime -= m_tottalTime;
	}

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_modelHandle, m_pos);
	//�����蔻��̉~���쐬
	m_col.SetRadius3D(m_pos.x, m_pos.y + kDefference, m_pos.z, m_radius);
	
	MV1SetAttachAnimTime(m_modelHandle, m_attachIndex, m_playTime);
}

void Player::Draw()
{
	//���f���̕`��
	MV1DrawModel(m_modelHandle);
#ifdef _DEBUG
	DrawFormatString(kDrawPos, kDrawPos, 0xffffff, "�v���C���[�̍��W(%.2f,%.5f)", m_pos.x, m_pos.z);
	m_col.DrawBall(0xff0000, 0xff0000, false);
#endif
}

void Player::SetData(DataLoader::Data inputData)
{
	m_pos.x = inputData.startPos.x;
	m_pos.z = inputData.startPos.z;
	m_speed = inputData.speed;
}
