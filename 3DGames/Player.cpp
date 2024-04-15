#include "Player.h"
#include "DxLib.h"
#include "Pad.h"
#include"Rect.h"

namespace
{
	//�W�����v��
	constexpr int kJumpPower = 25;

	//�����蔻��̒���
	constexpr int kRectX = 100;
	constexpr int kRectY = 75;

}

Player::Player() :
	m_JumpPower(0),
	m_Gravity(0),
	m_handle(-1),
	m_pos(VGet(0,0,150))
{

}

Player::~Player()
{
}

void Player::Init()
{

	m_handle = MV1LoadModel("data/player/Character.mv1");

	MV1SetScale(m_handle, VGet(0.5f, 0.5f,0.5f));

	ChangeLightTypeDir(VGet(-2.0f, 0.0f, -1.0f));

	MV1SetRotationXYZ(m_handle, VGet(0.0f, 250.0f * DX_PI_F / 180.0f, 0.0f));
}

void Player::Update()
{
	Pad::Update();
	// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (Pad::IsTrigger(PAD_INPUT_UP)&& m_pos.y == 0)
	{
		for (int i = 0; i < kJumpPower; i++)
		{
			m_JumpPower += i;
		}

		m_pos = VAdd(m_pos, VGet(0, m_JumpPower, 0));
	}	

	if (m_pos.y > 0)
	{
		m_Gravity += 1.0f;

		m_pos  = VAdd(m_pos, VGet(0, -m_Gravity, 0));
	}
	else if (m_pos.y <= 0)
	{
		m_Gravity = 0.0f;
		m_JumpPower = 0.0f;
		m_pos.y = 0;
	}

	//Player�̈ړ�
	m_pos = VAdd(m_pos,VGet(3,0,0)) ;

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	//�����蔻��̍X�V
	m_colRecto.SetCenter(m_pos.x, m_pos.y+ kRectY,m_pos.z, 40, 60);
}

void Player::Draw()
{
	MV1DrawModel(m_handle);

#ifdef _DEBUG
	//�@�����蔻��̕\��
	m_colRecto.Draw(GetColor(0, 0, 255), false);
	DrawFormatString(80, 80, GetColor(255, 255, 255), "�v���C���[�̍��W(%.2f,%.5f)", m_pos.x, m_pos.y);
#endif
}