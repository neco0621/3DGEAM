//�w�b�_�[�t�@�C���̃C���N���[�h
#include "Player.h"
#include "Game.h"

namespace
{
	constexpr float kSpeed	= 7.0f;
	constexpr float kRadius = 70.0f;
	constexpr float kScale	= 0.5f;
}

Player::Player() :
	//������
	m_modelHandle(-1),
	m_radius(kRadius),
	m_pos(VGet(540,0,360)),
	m_speed(kSpeed),
	m_scale(kScale)
{
	//���f�������[�h
	m_modelHandle = MV1LoadModel("data/model/Character.mv1");
	//SetData(m_data[m_usedataName]);
}

Player::~Player()
{
	//�������̊J��
	MV1DeleteModel(m_modelHandle);
}

void Player::Init()
{
	//���f���̃T�C�Y�𒲐�
	MV1SetScale(m_modelHandle, VGet(0.5f, 0.5f, 0.5f));
	//���C�g���g�����g��Ȃ���
	SetUseLighting(FALSE);
}

void Player::Update()
{
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

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_modelHandle, m_pos);
	//�����蔻��̉~���쐬
	m_col.SetRadius3D(m_pos.x,m_pos.y + 50,m_pos.z,m_radius);
}

void Player::Draw()
{
	//���f���̕`��
	MV1DrawModel(m_modelHandle);
#ifdef _DEBUG
	DrawFormatString(80, 80, 0xffffff, "�v���C���[�̍��W(%.2f,%.5f)", m_pos.x, m_pos.z);
	m_col.DrawBall(0xff0000, 0xff000000, false);
#endif
}

void Player::SetData(DataLoader::Data inputData)
{
	m_pos.x = inputData.startPos.x;
	m_pos.z = inputData.startPos.z;
	m_speed = inputData.speed;
}
